/* Boost.Flyweight test of intermodule_holder.
 *
 * Copyright 2006-2008 Joaquin M Lopez Munoz.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * See http://www.boost.org/libs/flyweight for library home page.
 */

#include "intermod_holder_dll.hpp"
#include <iostream>

intermodule_flyweight_string create_intermodule_flyweight_string(
  const std::string& str)
{
  std::cout<<"DLL: "<<typeid(intermodule_flyweight_string::holder_arg).name()<<std::endl;
  return intermodule_flyweight_string(str);
}
