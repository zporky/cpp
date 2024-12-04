
#include <vector>
#include "reverse.h"

int main()
{
  std::vector<int>    vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int>    vi2 = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  std::vector<int>    vi3 = { 21, 22, 23, 24, 25, 26, 27, 28, 29};
  std::vector<double> vd  = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1};
//  std::vector<std::vector<int>> vv = { vi1, vi2, vi3 };

  reverse(vi1);
  reverse(vi2);
  reverse(vi3);
  reverse(vd);
//  reverse(vv);

  print(std::cout,vi1);
  print(std::cout,vi2);
  print(std::cout,vi3);
  print(std::cout,vd);
//  print(std::cout,vv);

  return 0;
}
