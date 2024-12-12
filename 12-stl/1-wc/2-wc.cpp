#include <cctype>
#include <iostream>
#include <vector>
#include <numeric>

int wordcount(const std::vector<char>& v)
{
  if ( v.empty() )
    return 0;

  char prev = *v.begin();
  return std::accumulate(v.begin()+1, v.end(), // sum = op(sum,curr)
		std::isspace(prev) ? 0 : 1,
		[&prev](int sum,char curr) {
		int incr = std::isspace(prev) && !std::isspace(curr);
		prev = curr;
		return sum + incr;
	});
}

int main()
{
  const char s[] = "this is a sentence with a few words inside ";
  std::vector<char> v{std::begin(s), std::end(s)-1};
  std::cout << wordcount(v) << '\n';
  return 0;
}
