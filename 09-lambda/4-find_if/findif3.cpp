#include <iostream>
#include <vector> 
#include <algorithm>


int main()
{
  std::array<int,8> v = { 1, 3, 5, 4, 2, 9, 8, 7 };
  
  auto it = std::find_if(v.begin(), v.end(), [](int n) { return n%2; });

  int index = it - v.begin(); // only for array and vector
  std::cout << "v[" << index << "] == " << *it << '\n';
  return 0;  
}


