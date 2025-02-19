#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
  std::vector<int> v(1000);
  std::generate( v.begin(), v.end(), []() { return std::rand(); });
  std::for_each( v.begin(), v.end(), [](int x) { std::cout << x << ' '; });
  std::cout << '\n';

  return 0;
}
