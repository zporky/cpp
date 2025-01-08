#include "CppUTest/TestHarness.h"
#include <limits>

int factorial( int x)
{
  return x<=1 ? 1 : x*factorial(x-1);	
}
TEST_GROUP(FactorialTestGroup) { };
TEST(FactorialTestGroup, BasicTest)
{
   CHECK_EQUAL(  1, factorial(1));
   CHECK_EQUAL(120, factorial(5));
   CHECK_EQUAL(  1, factorial(0) );
   CHECK_EQUAL(479001600, factorial(12) );
}   
TEST(FactorialTestGroup, OverflowTest)
{
   CHECK_EQUAL(std::numeric_limits<int>::max(), factorial(13)); // overflow
}
TEST(FactorialTestGroup, StatelessTest)
{
   CHECK_EQUAL(   1, factorial(0) );    // check: no internal state
   CHECK_EQUAL( 120, factorial(5) );
}


