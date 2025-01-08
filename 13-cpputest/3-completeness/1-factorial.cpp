#include "CppUTest/TestHarness.h"

int factorial( int x)
{
  return 1==x ? 1 : 120;	
}
TEST_GROUP(FactorialTestGroup) { };
TEST(FactorialTestGroup, FirstTest)
{
   CHECK_EQUAL(1,   factorial(1));
   CHECK_EQUAL(120, factorial(5));
}
