/* Copyright 2024 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#ifndef BOOST_FLYWEIGHT_CONCURRENT_FACTORY_HPP
#define BOOST_FLYWEIGHT_CONCURRENT_FACTORY_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <atomic>
#include <boost/assert.hpp>
#include <boost/core/allocator_access.hpp> 
#include <boost/core/invoke_swap.hpp>
#include <boost/flyweight/concurrent_factory_fwd.hpp>
#include <boost/flyweight/factory_tag.hpp>
#include <boost/mpl/aux_/lambda_support.hpp>
#include <boost/mpl/if.hpp>
#include <boost/unordered/concurrent_node_set.hpp>
#include <chrono>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <utility>

/* flyweight factory based on boost::concurent_node_set */

namespace boost{

namespace flyweights{

namespace concurrent_factory_detail{

template<typename Entry>
struct refcounted_entry:Entry
{
  explicit refcounted_entry(Entry&& x):Entry{std::move(x)}{}
  refcounted_entry(refcounted_entry&& x):Entry{std::move(x)}{}

  long count()const{return ref;}
  void add_ref()const{++ref;}
  void release()const{--ref;} 
  
private:  
  mutable std::atomic_long ref{0};
};

template<typename RefcountedEntry>
class refcounted_handle
{
public:
  refcounted_handle(const refcounted_handle& x):p{x.p}{p->add_ref();}
  ~refcounted_handle(){p->release();}

  refcounted_handle& operator=(refcounted_handle x)
  {
    boost::core::invoke_swap(p,x.p);
    return *this;
  }

  const RefcountedEntry& get()const{return *p;}

private:
  template<typename,typename,typename,typename,typename>
  friend class ::boost::flyweights::concurrent_factory_class;

  refcounted_handle(const RefcountedEntry* p_):p{p_}
  {
    /* Doesn't add ref, refcount already incremented by
     * concurrent_factory_class before calling this ctor.
     */
    BOOST_ASSERT(p!=nullptr);
    BOOST_ASSERT(p->count()>0);
  }

  const RefcountedEntry* p;
};

} /* namespace concurrent_factory_detail */

template<
  typename Entry,typename Key,
  typename Hash,typename Pred,typename Allocator
>
class concurrent_factory_class:public factory_marker
{
  using entry_type=concurrent_factory_detail::refcounted_entry<Entry>;
  using unrebound_allocator_type=typename boost::mpl::if_<
    mpl::is_na<Allocator>,
    std::allocator<entry_type>,
    Allocator
  >::type;
  using container_type=boost::concurrent_node_set<
    entry_type,
    typename boost::mpl::if_<
      mpl::is_na<Hash>,
      boost::hash<Key>,
      Hash
    >::type,
    typename boost::mpl::if_<
      mpl::is_na<Pred>,
      std::equal_to<Key>,
      Pred
    >::type,
    boost::allocator_rebind_t<unrebound_allocator_type,entry_type>
  >;

  static constexpr auto gc_time=std::chrono::seconds(1);

public:
  using handle_type=concurrent_factory_detail::refcounted_handle<entry_type>;
  
  concurrent_factory_class():gc{[this]{
    /* Garbage collector. Traverses the container every gc_time and lockedly
     * erases entries without any external reference.
     */

    for(;;){
      {
        std::unique_lock<std::mutex> lk{m};
        if(cv.wait_for(lk,gc_time,[&]{return stop;}))return;
      }
      cont.erase_if([&](const entry_type& x){return !x.count();});
    }
  }}
  {}

  ~concurrent_factory_class()
  {
    /* shut the garbage collector down */

    {
      std::unique_lock<std::mutex> lk{m};
      stop=true;
    }
    cv.notify_one();
    gc.join();
  }

  handle_type insert(Entry&& x)
  {
    const entry_type* p=nullptr;
    auto              f=[&p](const entry_type& x){
      x.add_ref();
      p=std::addressof(x);
    };

    cont.insert_and_cvisit(entry_type{std::move(x)},f,f);
    return {p};
  }

  void erase(handle_type)
  {
    /* unused entries taken care of by garbage collector */
  }

  static const Entry& entry(handle_type h){return h.get();}

private:  
  container_type          cont;
  std::mutex              m;
  std::condition_variable cv;
  bool                    stop=false;
  std::thread             gc;

public:
  typedef concurrent_factory_class type;
  BOOST_MPL_AUX_LAMBDA_SUPPORT(
    5,concurrent_factory_class,(Entry,Key,Hash,Pred,Allocator))
};

/* concurrent_factory_class specifier */

template<
  typename Hash,typename Pred,typename Allocator
  BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION_DEF
>
struct concurrent_factory:factory_marker
{
  template<typename Entry,typename Key>
  struct apply:
    mpl::apply2<
      concurrent_factory_class<
        boost::mpl::_1,boost::mpl::_2,Hash,Pred,Allocator
      >,
      Entry,Key
    >
  {};
};

} /* namespace flyweights */

} /* namespace boost */

#endif
