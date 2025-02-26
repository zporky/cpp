#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ranges>

// g++ -Wall -Wextra 3-range.cpp -std=c++20
void print( auto c)
{
  for ( auto [x,y] : c ) 
  {
    std::cout << x << ':' << y << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::vector<int> v(1000);
  std::generate( v.begin(), v.end(), []() { return std::rand(); });

  print (v | std::views::transform(
                       [cnt=0](auto x) mutable { return std::pair{cnt++,x}; }) 
           | std::views::take(10) );
  std::cout << '\n';
  print( v | std::views::transform(
                       [cnt=-1, ptr=(int*)0] (auto& x) mutable { 
		         if( ptr != &x) {
			   ptr = &x; ++cnt;
			 } 
		         return std::pair{cnt,x}; 
		       }) 
	   | std::views::filter( [] (auto x) { return x.second % 2; } )
           | std::views::take(10) );

  return 0;
}
