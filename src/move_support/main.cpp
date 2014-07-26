//
// Copyright (c) 2010-2013 Marat Abrarov (abrarov@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#if defined(WIN32)
#include <tchar.h>
#include <windows.h>
#endif

#include <cstdlib>
#include <utility>
#include <exception>
#include <iostream>
#include <functional>
#include <boost/bind.hpp>

namespace {

class explicit_movable
{
private:
  typedef explicit_movable this_type;

public:
  explicit_movable()
  {
  }

  explicit_movable(const this_type&)
  {
    std::cout << "copy ctor" << std::endl;
  }

  explicit_movable(this_type&&)
  {
    std::cout << "move ctor" << std::endl;
  }

  ~explicit_movable()
  {
  }
}; // explicit_movable

class implicit_movable
{
private:
  typedef implicit_movable this_type;

public:

private:
  explicit_movable explicit_movable_;
}; // implicit_movable

void func(const explicit_movable&)
{
}

} // anonymous namespace

#if defined(WIN32)
int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
#else
int main(int /*argc*/, char* /*argv*/[])
#endif
{
  try
  {
    {
      std::cout << "Implicit move ctor generation" << std::endl;
      implicit_movable a;
      std::cout << "Moving... ";
      implicit_movable b(std::move(a));
      (void)b;
    }
    {
      std::cout << "Move ctor for std::bind generated functors" << std::endl;
      auto fa(std::bind(func, explicit_movable()));
      std::cout << "Moving... ";
      auto fb = std::move(fa);
      (void)fb;
    }
    {
      std::cout << "Move ctor for boost::bind generated functors" << std::endl;
      auto fa(boost::bind(func, explicit_movable()));
      std::cout << "Moving... ";
      auto fb = std::move(fa);
      (void)fb;
    }
    {
      std::cout << "Implicit move ctor for lambdas" << std::endl;
      explicit_movable a;
      auto fa = [a](){};
      std::cout << "Moving... ";
      auto fb(std::move(fa));
      (void)fb;
    }
    {
      std::cout << "Implicit move ctor for lambdas those capture by ref" 
                << std::endl;      
      explicit_movable a;
      explicit_movable b;
      auto fa = [a, &b](){};
      std::cout << "Moving... ";
      auto fb(std::move(fa));
      (void)fb;
    }
    return EXIT_SUCCESS;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  catch (...)
  {
    std::cerr << "Unexpected error" << std::endl;
  }
  return EXIT_FAILURE;
}
