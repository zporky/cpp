#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

struct MyClass
{
  int func(int x) {
     mock().actualCall("func").onObject(this).withParameter("x",x);	  	  
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
   mock().expectOneCall("func").onObject(&m).withParameter("x",1);
   CHECK_EQUAL(42, m.func(1));
   mock().checkExpectations();
}   
