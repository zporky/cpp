#include "CppUTest/TestHarness.h"

TEST_GROUP(AssertionTestGroup) { };
TEST(AssertionTestGroup, Check)
{
   CHECK( 10./3. == 3.3333  );
}   
TEST(AssertionTestGroup, CheckEqual)
{
   CHECK_EQUAL(3.3333, 10./3. );
}
TEST(AssertionTestGroup, BadDoublesEqual)
{
   DOUBLES_EQUAL(3.3333, 10/3, 0.01);
}
TEST(AssertionTestGroup, DoublesEqual)
{
   DOUBLES_EQUAL(3.3333, 10./3., 0.01);
}
