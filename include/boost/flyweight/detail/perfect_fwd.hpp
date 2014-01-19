/* Copyright 2006-2014 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#ifndef BOOST_FLYWEIGHT_DETAIL_PERFECT_FWD_HPP
#define BOOST_FLYWEIGHT_DETAIL_PERFECT_FWD_HPP

/* Brute force implementation of perfect forwarding overloads.
 * Usage:
 *
 *  # define NAME ...
 *  # define BODY(n) {...BOOST_FLYWEIGHT_PERFECT_FWD_ARGS(n)...}
 *  BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body)
 *
 * where NAME includes the return type and qualifiers (if any) and
 * BODY(n), where n is the no of args of the overload for which it is being
 * expanded, is expected to forward args via the provided utiliy macro
 * BOOST_FLYWEIGHT_PERFECT_FWD_ARGS(n)
 *
 * In compilers capable of perfect forwarding, the real thing is provided
 * (just one variadic args overload is generated).
 */

#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)||\
    defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES)

#include <boost/preprocessor/repetition/enum_params.hpp>

#define BOOST_FLYWEIGHT_PERFECT_FWD_ARGS(n) \
BOOST_PP_ENUM_PARAMS(n,t)

/* This user_definable macro limits the maximum number of arguments to
 * be perfect forwarded. Beware combinatorial explosion: manual perfect
 * forwarding for n arguments produces 2^n distinct overloads.
 */

#if !defined(BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS)
#define BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS 5
#endif

#if BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS<=5
#include <boost/flyweight/detail/pp_perfect_fwd.hpp>
#else
#include <boost/flyweight/detail/dyn_perfect_fwd.hpp>
#endif

#else

/* real perfect forwarding */

#include <utility>

#define BOOST_FLYWEIGHT_PERFECT_FWD_ARGS(_)              \
std::forward<Args>(args)...

#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body) \
template<typename... Args>name(Args&&... args)body(~)

#endif
#endif
