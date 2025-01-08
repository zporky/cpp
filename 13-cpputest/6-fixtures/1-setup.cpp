#include <iostream>    
#include "CppUTest/TestHarness.h"


TEST_GROUP(LogTestGroup) 
{ 
  void setup()
  {
    std::cerr << "setup LogTestGroup\n";	  
  }
  void teardown()
  {
    std::cerr << "teardown LogTestGroup\n";
  }
};

TEST(LogTestGroup, First)
{
  std::cerr << "First\n";	
}

TEST(LogTestGroup, Second)
{
  std::cerr << "Second\n";	
}

