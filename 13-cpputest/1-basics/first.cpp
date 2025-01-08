#include "CppUTest/CommandLineTestRunner.h"


TEST_GROUP(FirstTestGroup) { };
TEST(FirstTestGroup, FirstTest)
{
   CHECK_EQUAL(1, 1);
}
int main(int ac, char** av)
{
   return CommandLineTestRunner::RunAllTests(ac, av);
}
