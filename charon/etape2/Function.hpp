#ifndef __FUNCTION_HPP__
#define __FUNCTION_HPP__

#include <boost/bind.hpp>
#include "FunctionSignature.hpp"

template <typename T> class Function;
template <typename Arg, typename Ret>
class	Function<Ret (Arg)> {
private:
  typedef Ret (*type)(Arg);
public:
  Function();
  Function(type);
  ~Function();
  Ret				operator()(Arg);
  Function&	        operator=(type);
private:
  type	ptr;
};

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function() {
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::~Function() {  
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>::Function(type t) {
  ptr = t;
}

template <typename Arg, typename Ret>
Ret			Function<Ret (Arg)>::operator()(Arg a) {
  return ptr(a);
}

template <typename Arg, typename Ret>
Function<Ret (Arg)>&	Function<Ret (Arg)>::operator=(type t) {
  ptr = t;
  return *this;
}

#endif
