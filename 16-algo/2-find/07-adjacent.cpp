#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main(int argc, char **argv)
{
  std::vector<std::string> v{};
  std::copy( std::istream_iterator<std::string>{std::cin},
             std::istream_iterator<std::string>{}, 
	     std::back_inserter(v));

  auto it = std::adjacent_find( v.begin(), v.end());
  if ( v.end() == it )
    std::cout << "Not found\n";
  else  
    std::cout << "Found at index " << std::distance(v.begin(),it) << " " 
	      << *it << " " << *(it+1) << '\n';

}

// grep function ansi-c.txt
