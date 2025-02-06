#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<char> v{};
  std::cin >> std::noskipws;
  std::copy( std::istream_iterator<char>{std::cin},
  std::istream_iterator<char>{}, std::back_inserter(v));
  
  int cnt = 0;
  char prev = '\n'; // the imaginary char on -1 position is a white space.
  for ( char curr : v )
  {
    if ( std::isspace(prev) && !std::isspace(curr) ) // new word starts
      ++cnt;
    prev = curr;
  }
  std::cout << cnt << '\n';
}
