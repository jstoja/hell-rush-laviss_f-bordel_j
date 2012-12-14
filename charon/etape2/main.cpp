#include <iostream>
#include <boost/bind.hpp>
#include "Function.hpp"
#include "FunctionSignature.hpp"
#include "Callable.hpp"

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
  /* etape 2 */

  std::cout << "TEST operator =" << std::endl;

  Function<int (const char*)> functor;
  functor = &myTest;
  functor("test operator = : SUCCESS");

  std::cout << "TEST constructor with assignation" << std::endl;
  Function<int (const char*)> functor2 = &myTest;
  functor("test constructor with assignation : SUCCESS");

  std::cout << "TEST callable object" << std::endl;
  Callable1	call1;
  Function<void (char)> functor3 = &call1;
  functor3('a');

  //  Function<void (char)> functor3 = call1();
  //  std::cout << "TEST boost::bind with function" << std::endl;
  //  int (*debug)(char) = boost::bind(&boost_test);
  //  Function<int (char)> functor_bind = boost::bind(&boost_test, 'a');
  return 0;
}
