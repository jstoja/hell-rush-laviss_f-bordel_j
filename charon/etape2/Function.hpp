#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <iostream>
#include <memory>
#include <boost/bind.hpp>
#include "FunctionSignature.hpp"

template <typename T> class Functor;
template <typename Arg, typename Ret>
class Functor<Ret (Arg)>
{
public:
  virtual Ret operator()(Arg) = 0;
  virtual ~Functor(){};
};

template <typename T> class Function;
template <typename Arg, typename Ret>
class	Function<Ret (Arg)> {
  typedef Ret (*type)(Arg);  
public:
  Function();
  Function(Functor<Ret (Arg)> *);
  Function(type);
  ~Function();
  Ret			operator()(Arg);
  Function&	operator=(type);
  Function&	operator=(Functor<Ret (Arg)> *);
private:
  Functor<Ret (Arg)>	*_functor;
  type	ptr;
};

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function(Functor<Ret (Arg)> *f) {  
  ptr = NULL;
  _functor = f;
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function() {
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::~Function() {  
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function(type t) {
  ptr = t;
  _functor = NULL;
}

template <typename Arg, typename Ret>
Ret			Function<Ret (Arg)>::operator()(Arg a) {
  if (_functor != NULL)
    return (*_functor)(a);
  return ptr(a);
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>&	Function<Ret (Arg)>::operator=(type t) {
  ptr = t;
  _functor = NULL;
  return *this;
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>&	Function<Ret (Arg)>::operator=(Functor<Ret (Arg)> *f) {
  ptr = NULL;
  _functor = f;
  return *this;
}

#endif
