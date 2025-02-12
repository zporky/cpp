#include <iostream>

int main()
{
  int i = 42;	

  auto           x =  i;
  decltype(auto) y =  i;
  decltype(auto) z = (i);

  ++x;
  std::cout << "x == " << x << ", i == " << i << '\n';
  ++y;
  std::cout << "y == " << y << ", i == " << i << '\n';
  ++z;
  std::cout << "y == " << z << ", i == " << i << '\n';
}

