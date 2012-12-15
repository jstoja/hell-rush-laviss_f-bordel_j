#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <iostream>
#include <memory>
#include <boost/bind.hpp>
#include <boost/function.hpp>
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
  Function(Function<Ret (Arg)> const&);
  Function(Functor<Ret (Arg)> *);
  Function(type);
  Function(boost::function<Ret (Arg)>);
  ~Function();
  Ret			operator()(Arg);
  Function&	operator=(type);
  Function&	operator=(Functor<Ret (Arg)> *);
  Function&	operator=(boost::function<Ret (Arg)>);
  boost::function<Ret (Arg)>	getFunc() const { return _func; }
  Functor<Ret (Arg)>*		getFunctor() const { return _functor; }
  type					getType() const { return _ptr; }
private:
  boost::function<Ret (Arg)>	_func;
  Functor<Ret (Arg)>		*_functor;
  type					_ptr;
};

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function(Function<Ret (Arg)> const& cpy) {
  _func = cpy.getFunc();
  _functor = cpy.getFunctor();
  _ptr = cpy.getType();
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function(boost::function<Ret (Arg)> func) {
  _func = func;
  _ptr = NULL;
  _functor = NULL;
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function(Functor<Ret (Arg)> *f) {  
  _ptr = NULL;
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
  _ptr = t;  
  _functor = NULL;
}

template <typename Arg, typename Ret>
Ret			Function<Ret (Arg)>::operator()(Arg a) {
  if (_functor != NULL)
    return (*_functor)(a);
  else if (_ptr != NULL)
    return _ptr(a);
  return _func(a);
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>&	Function<Ret (Arg)>::operator=(type t) {
  _ptr = t;
  _functor = NULL;  
  return *this;
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>&	Function<Ret (Arg)>::operator=(Functor<Ret (Arg)> *f) {
  _ptr = NULL;
  _functor = f;
  return *this;
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>&	Function<Ret (Arg)>::operator=(boost::function<Ret (Arg)> func) {
  _func = func;
}

#endif
