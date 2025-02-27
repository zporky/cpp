#include <iostream>
#include "x.h"

int main()
{
  X x{"hello"};
  X y = x;
  x.print();
  std::cout << '\n';

  y.add("word");
  y.print();
  std::cout << '\n';

  return 0;  
}
