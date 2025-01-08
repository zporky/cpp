#include <unordered_set>    // swap line 1 and 2
#include "CppUTest/TestHarness.h"

void add(std::unordered_set<int> &s, int x)
{
  s.insert(x);
}

TEST_GROUP(HashSetTestGroup) { };
TEST(HashSetTestGroup, InsertTest)
{
   std::unordered_set<int> s;
   add(s,1);   
   add(s,3);
   add(s,2);   
   CHECK_EQUAL(3, *s.begin());
}

