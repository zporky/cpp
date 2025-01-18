//  g++ -Wall -Wextra test.cpp testmain.cpp -lCppUTest
#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
   return CommandLineTestRunner::RunAllTests(ac, av);
}
