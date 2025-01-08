#include "CppUTest/TestHarness.h"

const char *hello = "Hello"; 	

TEST_GROUP(PointersTestGroup) { };
TEST(PointersTestGroup, Check)
{
   CHECK( "Hello" == hello );
}   
TEST(PointersTestGroup, PointersEqual)
{
   POINTERS_EQUAL("Hello", hello);
}
TEST(PointersTestGroup, NocasePointersEqual)
{
   POINTERS_EQUAL("heLLo", hello);
}
TEST(PointersTestGroup, DifferentPointers)
{
   const char *hello2 = "SayHelloToEverybody"; 	
   POINTERS_EQUAL("Hello", hello2);
}

