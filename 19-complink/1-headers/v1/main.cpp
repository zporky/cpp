#include <iostream>
#include "x.h"

int main()
{
  X x{"hello"};
  x.add("word");

  x.print();
  std::cout << '\n';

  return 0;  
}
