#include <cctype>
#include <iostream>
#include <vector>

int wordcount(const std::vector<char>& v)
{

}

int main()
{
  const char s[] = "this is a sentence with a few words inside ";
  std::vector<char> v{std::begin(s), std::end(s)};
  std::cout << wordcount(v) << '\n';
  return 0;
}
