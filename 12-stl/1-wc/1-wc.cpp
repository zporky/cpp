#include <cctype>
#include <iostream>
#include <vector>

int wordcount(const std::vector<char>& v)
{
  int cnt = 0;
  char prev = '\n'; // the imaginary char on -1 position is a white space.
  for ( char curr : v )
  {
    if ( std::isspace(prev) && !std::isspace(curr) ) // new word starts
    {
      ++cnt;
    }
    prev = curr;
  }
  return cnt;
}

int main()
{
  const char s[] = "this is a sentence with a few words inside ";
  std::vector<char> v{std::begin(s), std::end(s)};
  std::cout << wordcount(v) << '\n';
  return 0;
}
