
#include <cctype>
#include <iostream>
#include <vector>
#include <numeric>
#include <execution>

int wordcount(const std::vector<char>& v)
{
  if ( v.empty() )
    return 0;
 
  return std::transform_reduce(std::execution::par,
  	        v.begin(), v.end()-1, // binop(*it1,*i2)
	        v.begin()+1,
		std::isspace(v.front()) ? 0 : 1,
		std::plus{},
		[](char curr,char next) {
		return std::isspace(curr) && !std::isspace(next);
	});
}

int main() // g++ -ltbb
{
	const char s[] = "this is a sentence with a few words inside ";
	std::vector<char> v{std::begin(s), std::end(s)-1};
	std::cout << wordcount(v) << '\n';
	return 0;
}
