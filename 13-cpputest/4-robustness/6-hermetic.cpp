#include <iostream>    
#include <fstream>    
#include <filesystem>
#include "CppUTest/TestHarness.h"

void log(std::ostream& os)
{
  os << "Log from " << __FILE__ << ", " << __LINE__ << '\n';
}

TEST_GROUP(LogTestGroup) { };

TEST(LogTestGroup, LogContent)
{
  
   std::ofstream logfile{"logfile.txt"};
   log(logfile);   
   CHECK( std::filesystem::exists("logfile.txt"));
}

