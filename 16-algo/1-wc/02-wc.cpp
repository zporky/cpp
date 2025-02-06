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
  
  char prev = '\n';
  int cnt = 0;
  
  if ( ! v.empty() )
  {
   cnt = std::accumulate(std::begin(v), std::end(v), 0,
                         [&prev](char curr){ 
			  auto x = std::isspace(prev) && !std::isspace(curr); 
			  prev = curr;
		        });
  }
  std::cout << cnt << '\n';
}
