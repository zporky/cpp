#include <iostream>    
#include <fstream>    
#include <sstream>    
#include <filesystem>
#include <thread>
#include "CppUTest/TestHarness.h"

void log(std::ostream& os)
{
  os << "Log from " << __FILE__ << ", " << __LINE__ << '\n';
}

TEST_GROUP(LogTestGroup) { };

TEST(LogTestGroup, LogContent)
{
   std::ostringstream os;
   std::thread::id id = std::this_thread::get_id();
   os << id;

   std::string fname{"logfile"};
   fname += os.str();
   fname += ".txt";
   
   std::filesystem::remove(fname);
   std::ofstream logfile{fname};
   log(logfile);   
   CHECK( std::filesystem::exists(fname) );
}

