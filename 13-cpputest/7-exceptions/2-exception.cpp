#include <stdexcept>
#include "CppUTest/TestHarness.h"

int factorial( int x)
{
  if ( x < 0 )
    throw std::invalid_argument{"less than zero"};	  
  return x <= 1 ?  1 : x*factorial(x-1);	
}
TEST_GROUP(FactorialTestGroup) { };
TEST(FactorialTestGroup, BasicTest)
{
   CHECK_EQUAL(  1, factorial(1));
   CHECK_EQUAL(120, factorial(5));
   CHECK_EQUAL(  1, factorial(0) );
   CHECK_EQUAL(479001600, factorial(12) );
}   
TEST(FactorialTestGroup, BadArgument)
{
   CHECK_THROWS(std::invalid_argument, factorial(-1) );   
   CHECK_THROWS( std::exception,  factorial(-1) );
   CHECK_THROWS( std::out_of_range,  factorial(-1) );
}
