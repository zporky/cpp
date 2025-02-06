#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
  std::vector<char> v{};
  std::cin >> std::noskipws;
  std::copy( std::istream_iterator<char>{std::cin},
  std::istream_iterator<char>{}, std::back_inserter(v));
  int cnt = 0;
 
  if ( ! v.empty() )
  {
   cnt = std::transform_reduce(
   std::begin(v), std::end(v)-1, std::begin(v)+1, 
   !std::isspace(v[0])?1:0, std::plus{},
 [](char curr, char next){ return std::isspace(curr) && !std::isspace(next); } );
  }
  std::cout << cnt << '\n';
}
