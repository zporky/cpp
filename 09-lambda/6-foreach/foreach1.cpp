#include <iostream>
#include <vector> 
#include <algorithm>

bool is_odd(int n)
{
  return n%2;
};

int main()
{
  std::array<int,8> v = { 1, 3, 5, 4, 2, 9, 8, 7 };
  
  auto it = std::for_each(v.begin(), v.end(), 
		  [](int n) { std::cout << n*n << ' '; });

  return 0;  
}


