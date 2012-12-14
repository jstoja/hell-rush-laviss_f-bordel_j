#ifndef __FUNCTIONSIGNATURE_HPP__
#define __FUNCTIONSIGNATURE_HPP__

template <typename T> struct FunctionSignature;
template <typename Arg, typename Ret>
struct FunctionSignature<Ret (Arg)> {
  typedef Ret (*type)(Arg);
};

template <typename Arg1, typename Arg2, typename Ret>
struct FunctionSignature<Ret (Arg1, Arg2)> {
  typedef Ret (*type)(Arg1, Arg2);
};

template <typename Arg1, typename Arg2, typename Arg3, typename Ret>
struct FunctionSignature<Ret (Arg1, Arg2, Arg3)> {
  typedef Ret (*type)(Arg1, Arg2, Arg3);
};

template <typename Arg1, typename Arg2,  typename Arg3, typename Arg4, typename Ret>
struct FunctionSignature<Ret (Arg1, Arg2, Arg3, Arg4)> {
  typedef Ret (*type)(Arg1, Arg2, Arg3, Arg4);
};

#endif
