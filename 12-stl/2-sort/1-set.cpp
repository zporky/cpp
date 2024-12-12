
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>

int main() /* print unique sorted elems */
{
  std::set<std::string> coll( std::istream_iterator<std::string>(std::cin), 
		              std::istream_iterator<std::string>());
  std::copy( coll.begin(), coll.end(), 
		     std::ostream_iterator<std::string>(std::cout, "\n"));
  return 0;
}
