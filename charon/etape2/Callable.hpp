#ifndef _CALL_HPP__
#define _CALL_HPP__

#include <iostream>
#include "FunctionSignature.hpp"

template <typename T> class Functor;
template <typename Arg, typename Ret>
class Functor<Ret (Arg)>;


template <typename T> class Function;
template <typename Arg, typename Ret>
class	Function<Ret (Arg)>;

class Callable1 : public Functor<void (char)>
{
public:
  Callable1();
  ~Callable1();
  void operator()(char);
};

Callable1::Callable1()
{
}

Callable1::~Callable1()
{
}

void Callable1::operator()(char /* c */)
{
  std::cout << "Callable object : SUCCESS" << std::endl;
}

#endif
