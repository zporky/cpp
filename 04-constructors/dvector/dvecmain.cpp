
#include <iostream>
#include "dvector.h"


int main()
{
  DVector x;

  for (int i = 0; i < 10; ++i )
    x.push_back(i);

  DVector y;

  for (int i = 0; i < 15; ++i )
    y.push_back(i+20);

  std::cout << "x = [ ";
  for (int i = 0; i < x.size(); ++i )
    std::cout << x.at(i) << " ";
  std::cout << "]" << std::endl;

  std::cout << "y = [ ";
  for (int i = 0; i < y.size(); ++i )
    std::cout << y.at(i) << " ";
  std::cout << "]" << std::endl;

  x = y;
  std::cout << "x = y" << std::endl;

  std::cout << "x = [ ";
  for (int i = 0; i < x.size(); ++i )
    std::cout << x[i] << " ";
  std::cout << "]" << std::endl;

  std::cout << "y = [ ";
  for (int i = 0; i < y.size(); ++i )
    std::cout << y[i] << " ";
  std::cout << "]" << std::endl;

  x[0] = 999;
  std::cout << "x[0] = 999" << std::endl;
 
  std::cout << "x = [ ";
  for (int i = 0; i < x.size(); ++i )
    std::cout << x[i] << " ";
  std::cout << "]" << std::endl;

  std::cout << "y = [ ";
  for (int i = 0; i < y.size(); ++i )
    std::cout << y[i] << " ";
  std::cout << "]" << std::endl;

  return 0; 
}

