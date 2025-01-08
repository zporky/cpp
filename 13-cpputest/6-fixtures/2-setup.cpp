#include <iostream>    
#include "CppUTest/TestHarness.h"

struct MyStruct
{
  MyStruct()  { std::cerr << "MyStruct::MyStruct()"  << '\n'; }
  ~MyStruct() { std::cerr << "MyStruct::~MyStruct()" << '\n'; }
};


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
  MyStruct m;
};

TEST(LogTestGroup, First)
{
  std::cerr << "First\n";	
}

TEST(LogTestGroup, Second)
{
  std::cerr << "Second\n";	
}

