#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

int factorial( int x)
{
  mock().actualCall("factorial");	
  return x <= 1 ?  1 : x*factorial(x-1);	
}
TEST_GROUP(Mock) 
{ 
  void teardown()
  {
    mock().clear();	  
  }
};
TEST(Mock, CallOnce)
{
   mock().expectOneCall("factorial");
   CHECK_EQUAL(1, factorial(1));
   mock().checkExpectations();
}   
