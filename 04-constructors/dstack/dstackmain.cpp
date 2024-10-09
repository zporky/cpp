
#include <iostream>
#include "dstack.h"


int main()
{
  DStack x;

  for (int i = 0; i < 10; ++i )
    x.push(i);

  DStack y;

  for (int i = 0; i < 15; ++i )
    y.push(i+20);

  print( std::cout, x);
  print( std::cout, y);

  x = y;
  std::cout << "x = y" << std::endl;

  print( std::cout, x);
  print( std::cout, y);

  x.top() = 999;
  std::cout << "x.top() = 999" << std::endl;

  print( std::cout, x);
  print( std::cout, y);

  std::cout << "stress test for memory leaks..." << std::endl;
  for(int i = 0; i < 1000; ++i) // set to 100000 for real test
  {
    std::cout << i << " ";
    for(int j = 0; j < 1000; ++j) // set to 100000 for real test
    {
      DStack z1, z2;
      z1.push(j); z2.push(j);
      z1 = z2;
    }
  }
  std::cout << "  ... ok" << std::endl;

  return 0; 
}

