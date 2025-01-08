#include "CppUTest/TestHarness.h"

void increment(int& x)
{
    ++x;
}

static int count = 0;

TEST_GROUP(CountTestGroup) { };

TEST(CountTestGroup, First)
{
   increment(count);
   CHECK_EQUAL( 1, count );
}

TEST(CountTestGroup, Second)
{
   increment(count);
   CHECK_EQUAL( 2, count );
}

