#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main()
{
  std::vector<std::string> v{};
  std::copy( std::istream_iterator<std::string>{std::cin},
             std::istream_iterator<std::string>{}, 
	     std::back_inserter(v));
  
  std::cout << v.size() << '\n';
}
