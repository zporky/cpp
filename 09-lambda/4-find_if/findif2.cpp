#include <iostream>
#include <vector> 
#include <algorithm>

struct is_odd
{
  bool operator()(int n) { return n%2; }
};

int main()
{
  std::array<int,8> v = { 1, 3, 5, 4, 2, 9, 8, 7 };
  
  auto it = std::find_if(v.begin(), v.end(), is_odd{});

  int index = it - v.begin(); // only for array and vector
  std::cout << "v[" << index << "] == " << *it << '\n';
  return 0;  
}


