#include <iostream>
#include <boost/bind.hpp>
#include "Function.hpp"
#include "FunctionSignature.hpp"

int	myTest(const char *str)
{
  std::cout<< str << std::endl;
  return 1;
}

int toto(int /* a */, int /* b */)
{
  std::cout << "test 2 args : SUCCESS" << std::endl;
  return (0);
}

int titi(int /* a */, int /* b */, int /* c */, float /* d */)
{
  std::cout << "test 4 args : SUCCESS" << std::endl;
  return (0);
}

int tutu(int /* a */, int /* b */, int /* c */)
{
  std::cout << "test 3 args : SUCCESS" << std::endl;
  return (0);
}

int  boost_test(char /* c */)
{
  std::cout << "boost::bind : SUCCESS" << std::endl;
  return (0);
}

int	main()
{
  /* etape 1 */

  std::cout << "TEST 1 ARG" << std::endl;
  FunctionSignature<int (const char *)>::type f = &myTest;
  f("test 1 arg : SUCCESS");

  std::cout << "TEST 2 ARG" << std::endl;
  FunctionSignature<int (int, int)>::type f2 = &toto;
  f2(1,1);

  std::cout << "TEST 3 ARG" << std::endl;
  FunctionSignature<int (int, int, int)>::type f3 = &tutu;
  f3(1,1,1);

  std::cout << "TEST 4 ARG" << std::endl;
  FunctionSignature<int (int, int, int, float)>::type f4 = &titi;
  f4(1,1,1,1.1);

  /* etape 2 */

  std::cout << "TEST operator =" << std::endl;

  Function<int (const char*)> functor;
  functor = &myTest;
  functor("test operator = : SUCCESS");

  std::cout << "TEST constructor with assignation" << std::endl;
  Function<int (const char*)> functor2 = &myTest;
  functor("test constructor with assignation : SUCCESS");

  //  std::cout << "TEST boost::bind with function" << std::endl;
  //  int (*debug)(char) = boost::bind(&boost_test);
  //  Function<int (char)> functor_bind = boost::bind(&boost_test, 'a');
  return 0;
}
