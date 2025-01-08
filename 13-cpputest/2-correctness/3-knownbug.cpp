#include "CppUTest/TestHarness.h"

int square( int x)
{
  return x*x;  // TODO: implementing	
}
TEST_GROUP(FirstTestGroup) { };
TEST(FirstTestGroup, FirstTest)
{
   CHECK_EQUAL(0, square(0));
   CHECK_EQUAL(1, square(1));
   CHECK_EQUAL(4, square(2));
   CHECK_EQUAL(1764, square(42));
}
