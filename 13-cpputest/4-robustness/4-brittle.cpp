#include <iostream>    
#include <sstream>    
#include "CppUTest/TestHarness.h"

void log(std::ostream& os)
{
  os << "Log from " << __FILE__ << ", " << __LINE__ << '\n';
}

TEST_GROUP(LogTestGroup) { };

TEST(LogTestGroup, LogContent)
{
   log(std::cerr);
   std::ostringstream os{};
   log(os);   
   STRCMP_CONTAINS("4-brittle.cpp", os.str().c_str());
   STRCMP_CONTAINS("7",os.str().c_str());
}

