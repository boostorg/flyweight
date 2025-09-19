/* Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#ifndef BOOST_FLYWEIGHT_HASHED_FACTORY_FWD_HPP
#define BOOST_FLYWEIGHT_HASHED_FACTORY_FWD_HPP

#if defined(_MSC_VER)
#pragma once
#endif

#include <boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <boost/flyweight/detail/not_placeholder_expr.hpp>
#include <boost/mpl/aux_/na.hpp>

namespace boost{

namespace flyweights{

template<
  typename Entry,typename Key,
  typename Hash=mpl::na,typename Pred=mpl::na,typename Allocator=mpl::na
>
class hashed_factory_class;

template<
  typename Hash=mpl::na,typename Pred=mpl::na,typename Allocator=mpl::na
  ,int=666
  //BOOST_FLYWEIGHT_NOT_A_PLACEHOLDER_EXPRESSION
>
struct hashed_factory;

} /* namespace flyweights */

} /* namespace boost */

namespace boost{
namespace mpl{

template<
  template<typename,typename,typename,int> class F,
  typename H,typename P,typename A,
  typename Tag
>
struct lambda<F<H,P,A,666>,Tag>
{
  typedef F<H,P,A,666> type;
};

}
}

#endif
