#include <iostream>

struct C
{
public:
  bool operator==(const C& c)
  {
    std::cout << "equal" << std::endl;
    return this == &c;
  }

  bool operator!=(const C& c) const
  {
    std::cout << "not equal" << std::endl;
    return this != &c;
  }
};

int main()
{
  C c1, c2;
  bool b = c1 != c2;
  std::cout << std::boolalpha << b << '\n';
}
