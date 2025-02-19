#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ranges>

// g++ -Wall -Wextra 3-range.cpp -std=c++20
void print( const std::ranges::input_range auto& c)
{
  for ( auto e : c ) 
  {
    std::cout << e << ' ';
  }
  std::cout << '\n';
}

int main()
{
  std::vector<int> v(1000);
  std::generate( v.begin(), v.end(), []() { return std::rand(); });
  print( v | std::views::transform([](auto x ){ 
		 return std::to_string(x%10) + ":" + std::to_string(x); }) 
 	   | std::views::take(10) 
           | std::views::drop(4) );

  return 0;
}
