#include <cctype>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main(int argc, char **argv)
{
  if ( argc < 3 )
    return 1;	  
 
  std::string pattern1{argv[1]};
  std::string pattern2{argv[2]};

  std::vector<std::string> v{};
  std::copy( std::istream_iterator<std::string>{std::cin},
             std::istream_iterator<std::string>{}, 
	     std::back_inserter(v));

  std::vector<std::string> p{pattern1, pattern2};

  auto it = std::search( v.begin(), v.end(), p.begin(), p.end() );
  if ( v.end() == it )
    std::cout << "Not found\n";
  else  
    std::cout << "Found at index " << std::distance(v.begin(),it) << " " 
	      << *it << " " << *(it+1) << '\n';		           
}

// grep function argument ansi-c.txt
