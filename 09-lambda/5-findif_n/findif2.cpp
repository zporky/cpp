#include <iostream>
#include <vector> 
#include <algorithm>

struct is_odd_2nd
{
  int cnt = 0;	

  bool operator()(int n)
  {
    if ( n%2 )
      ++cnt;
    return 2 == cnt;
  }
};

int main()
{
  std::array<int,8> v = { 1, 3, 5, 4, 2, 9, 8, 7 };
  
  auto it = std::find_if(v.begin(), v.end(), is_odd_2nd{});
  //  it = std::find_if(it+1, v.end(), is_odd_2nd{});

  int index = it - v.begin(); // only for array and vector
  std::cout << "v[" << index << "] == " << *it << '\n';
  return 0;  
}


