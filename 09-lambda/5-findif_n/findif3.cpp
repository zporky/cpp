#include <iostream>
#include <vector> 
#include <algorithm>


int main()
{
  std::array<int,8> v = { 1, 3, 5, 4, 2, 9, 8, 7 };
  
  auto it = std::find_if(v.begin(), v.end(), 
      [cnt = 0](int n) mutable { if ( n%2 ) ++cnt; return 2 == cnt; });
  //   it = std::find_if(it+1, v.end(), 
  //  [cnt = 0](int n) mutable { if ( n%2 ) ++cnt; return 2 == cnt; });

  int index = it - v.begin(); // only for array and vector
  std::cout << "v[" << index << "] == " << *it << '\n';
  return 0;  
}


