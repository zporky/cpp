#include "CppUTest/TestHarness.h"

int square( int x)
{
  return 0;  // TODO: implementing	
}
TEST_GROUP(FirstTestGroup) { };
TEST(FirstTestGroup, FirstTest)
{
   CHECK_EQUAL(0, square(0));
   CHECK_EQUAL(0, square(1));
   CHECK_EQUAL(0, square(2));
   CHECK_EQUAL(0, square(42));
}
