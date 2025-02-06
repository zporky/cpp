#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
  if ( argc < 2 )
    return 1;	  
 
  std::string pattern{argv[1]};

  std::vector<std::string> v{};
  std::copy( std::istream_iterator<std::string>{std::cin},
             std::istream_iterator<std::string>{}, 
	     std::back_inserter(v));

  auto it = std::ranges::find_last(v, pattern);
  if ( v.end() == it )
    std::cout << "Not found\n";
  else  
    std::cout << "Found at index " << std::ranges::distance(it,v.begin())
	      << '\n';
}
