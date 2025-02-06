#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main(int argc, char **argv)
{
  if ( argc < 2 )
    return 1;	  
 
  std::string pattern{argv[1]};

  std::vector<std::string> v{};
  std::copy( std::istream_iterator<std::string>{std::cin},
             std::istream_iterator<std::string>{}, 
	     std::back_inserter(v));

  auto cnt = std::count( v.begin(), v.end(), pattern);
  std::cout << "Count: " << cnt << '\n';
}

// grep function ansi-c.txt
