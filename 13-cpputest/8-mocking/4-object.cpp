#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

struct MyClass
{
  int func(int x) {
     mock().actualCall("func").onObject(this);	  	  
     return 42;	
  }
};
TEST_GROUP(Mock) 
{ 
  void teardown()
  {
    mock().clear();	  
  }
};
TEST(Mock, CallOnObject)
{
   MyClass m{};
   mock().expectOneCall("func").onObject(&m);
   CHECK_EQUAL(42, m.func(1));
   mock().checkExpectations();
}   
