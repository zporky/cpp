#include "CppUTest/TestHarness.h"

const char *hello = "Hello"; 	

TEST_GROUP(StringTestGroup) { };
TEST(StringTestGroup, Check)
{
   CHECK( "Hello" == hello );
}   
TEST(StringTestGroup, CheckEqual)
{
   CHECK_EQUAL("Hello", hello);
}
TEST(StringTestGroup, StrcmpEqual)
{
   STRCMP_EQUAL( "Hello", hello);
}
TEST(StringTestGroup, StrcmpNocaseEqual)
{
   STRCMP_NOCASE_EQUAL("heLLo", hello);
}
TEST(StringTestGroup, StrcmpContains)
{
   const char *hello2 = "SayHelloToEverybody"; 	
   STRCMP_CONTAINS("Hello", hello2);
}

