#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
  std::vector<int> v(1000);
  std::generate( v.begin(), v.end(), []() { return std::rand(); });

  for ( auto e : v ) 
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
  return 0;
}
