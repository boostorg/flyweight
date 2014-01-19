/* Copyright 2006-2014 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#ifndef BOOST_FLYWEIGHT_DETAIL_PP_PERFECT_FWD_HPP
#define BOOST_FLYWEIGHT_DETAIL_PP_PERFECT_FWD_HPP

#if BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS>=1
#define BOOST_FLYWEIGHT_PERFECT_FWDS_1(name,body) \
template<typename T0> name(T0& t0)body(1)\
template<typename T0> name(const T0& t0)body(1)
#endif

#if BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS>=2
#define BOOST_FLYWEIGHT_PERFECT_FWDS_2(name,body) \
template<typename T0,typename T1> name(T0& t0,T1& t1)body(2)\
template<typename T0,typename T1> name(T0& t0,const T1& t1)body(2)\
template<typename T0,typename T1> name(const T0& t0,T1& t1)body(2)\
template<typename T0,typename T1> name(const T0& t0,const T1& t1)body(2)
#endif

#if BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS>=3
#define BOOST_FLYWEIGHT_PERFECT_FWDS_3(name,body) \
template<typename T0,typename T1,typename T2> name(T0& t0,T1& t1,T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(T0& t0,T1& t1,const T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(T0& t0,const T1& t1,T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(T0& t0,const T1& t1,const T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(const T0& t0,T1& t1,T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(const T0& t0,T1& t1,const T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(const T0& t0,const T1& t1,T2& t2)body(3)\
template<typename T0,typename T1,typename T2> name(const T0& t0,const T1& t1,const T2& t2)body(3)
#endif

#if BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS>=4
#define BOOST_FLYWEIGHT_PERFECT_FWDS_4(name,body) \
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,T1& t1,T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,T1& t1,T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,T1& t1,const T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,T1& t1,const T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,const T1& t1,T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,const T1& t1,T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,const T1& t1,const T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(T0& t0,const T1& t1,const T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,T1& t1,T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,T1& t1,T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,T1& t1,const T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,T1& t1,const T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,const T1& t1,T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,const T1& t1,T2& t2,const T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,const T1& t1,const T2& t2,T3& t3)body(4)\
template<typename T0,typename T1,typename T2,typename T3> name(const T0& t0,const T1& t1,const T2& t2,const T3& t3)body(4)
#endif

#if BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS>=5
#define BOOST_FLYWEIGHT_PERFECT_FWDS_5(name,body) \
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,const T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,const T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,const T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,T1& t1,const T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,const T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,const T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,const T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(T0& t0,const T1& t1,const T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,const T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,const T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,const T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,T1& t1,const T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,T2& t2,const T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,const T2& t2,T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,const T2& t2,T3& t3,const T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,const T2& t2,const T3& t3,T4& t4)body(5)\
template<typename T0,typename T1,typename T2,typename T3,typename T4> name(const T0& t0,const T1& t1,const T2& t2,const T3& t3,const T4& t4)body(5)
#endif

#if   BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS==0
#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body)
#elif BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS==1
#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body) \
BOOST_FLYWEIGHT_PERFECT_FWDS_1(name,body)
#elif BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS==2
#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body) \
BOOST_FLYWEIGHT_PERFECT_FWDS_1(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_2(name,body)
#elif BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS==3
#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body) \
BOOST_FLYWEIGHT_PERFECT_FWDS_1(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_2(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_3(name,body)
#elif BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS==4
#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body) \
BOOST_FLYWEIGHT_PERFECT_FWDS_1(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_2(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_3(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_4(name,body)
#else /* BOOST_FLYWEIGHT_LIMIT_PERFECT_FWD_ARGS==5 */
#define BOOST_FLYWEIGHT_PERFECT_FWD_OVERLOADS(name,body) \
BOOST_FLYWEIGHT_PERFECT_FWDS_1(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_2(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_3(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_4(name,body)                \
BOOST_FLYWEIGHT_PERFECT_FWDS_5(name,body)
#endif

#endif
