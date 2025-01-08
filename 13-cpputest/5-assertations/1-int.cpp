#include "CppUTest/TestHarness.h"

int factorial( int x)
{
  return x <= 1 ? 1 : x*factorial(x-1);	
}
TEST_GROUP(FactorialTestGroup) { };
TEST(FactorialTestGroup, FirstTest)
{
   CHECK( factorial(1) > 0 );	
   CHECK_EQUAL(1,   factorial(1));
   CHECK_FALSE( factorial(1) < 1 );
   CHECK_FALSE_TEXT(factorial(1) == 1, "Last test fails");
}
