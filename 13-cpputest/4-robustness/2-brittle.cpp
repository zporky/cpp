#include "CppUTest/TestHarness.h"
#include <unordered_set>

void add(std::unordered_set<int> &s, int x)
{
  s.insert(x);
}

TEST_GROUP(HashSetTestGroup) { };
TEST(HashSetTestGroup, InsertTest)
{
   std::unordered_set<int> s;
   add(s,1);   
   add(s,2);   
   add(s,3);
   CHECK_EQUAL(1, *s.begin());
};

