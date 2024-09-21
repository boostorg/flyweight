/* Boost.Flyweight test of concurrent_factory.
 *
 * Copyright 2024 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#include "test_concurrent_factory.hpp"

#include <boost/config.hpp> /* keep it first to prevent nasty warns in MSVC */
#include <boost/detail/workaround.hpp>
#include <boost/flyweight/flyweight.hpp>
#include <boost/flyweight/concurrent_factory.hpp> 
#include <boost/flyweight/no_locking.hpp>
#include <boost/flyweight/no_tracking.hpp>
#include <boost/flyweight/refcounted.hpp>
#include <boost/flyweight/simple_locking.hpp>
#include <boost/flyweight/static_holder.hpp>
#include <functional>
#include "test_basic_template.hpp"

using namespace boost::flyweights;

struct concurrent_factory_flyweight_specifier1
{
  template<typename T>
  struct apply
  {
    typedef flyweight<T,concurrent_factory<> > type;
  };
};

struct concurrent_factory_flyweight_specifier2
{
  template<typename T>
  struct apply
  {
    typedef flyweight<
      T,
      static_holder_class<boost::mpl::_1>,
      no_locking,
      no_tracking,
      concurrent_factory_class<
        boost::mpl::_1,boost::mpl::_2,
        std::hash<boost::mpl::_2>,
        std::equal_to<boost::mpl::_2>,
        std::allocator<boost::mpl::_1>
      >
    > type;
  };
};

struct concurrent_factory_flyweight_specifier3
{
  template<typename T>
  struct apply
  {
    typedef flyweight<
      T,
      concurrent_factory<

#if BOOST_WORKAROUND(BOOST_MSVC,<1930)
      /* std::hash<boost::mpl::_2> is spuriously and failingly instantiated
       * by Boost.MPL in msvc 14.0.
       */

        boost::hash<boost::mpl::_2>,
#else
        std::hash<boost::mpl::_2>,
#endif

        std::equal_to<boost::mpl::_2>,
        std::allocator<boost::mpl::_1>
      >,
      static_holder_class<boost::mpl::_1>,
      no_locking,
      no_tracking,
      tag<char>
    > type;
  };
};

void test_concurrent_factory()
{
  test_basic_template<concurrent_factory_flyweight_specifier1>();
  test_basic_template<concurrent_factory_flyweight_specifier2>();
  test_basic_template<concurrent_factory_flyweight_specifier3>();
}
