
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>

int main() /* print unique sorted elems */
{
  std::vector<std::string> coll( std::istream_iterator<std::string>(std::cin), 
		                 std::istream_iterator<std::string>());
  std::sort( coll.begin(), coll.end());
  std::unique_copy( coll.begin(), coll.end(), 
   	     std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
