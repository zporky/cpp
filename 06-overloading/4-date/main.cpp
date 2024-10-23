
#include <iostream>
#include <exception>
#include "date.h"

int main()
{
  Date d1{2016, 4};   // this should be 2016.04.01
  Date d2 = d1;       // copy constructor, 
  d2 += 40;           // add 40 days  
  d1 = d2;            // assignment, now d1 is 2016.05.11

  std::cout << "d1++ == " << d1++ << '\n'; // 2016.05.11
  std::cout << " d1  == " <<  d1  << '\n'; // 2016.05.12
  std::cout << "++d2 == " << ++d2 << '\n'; // 2016.05.12
  std::cout << " d2  == " <<  d2  << '\n'; // 2016.05.12

  Date d3{2024};
  std::cout << "d3 == " << d3 << '\n';
  std::cout << "d3 += 99\n";
  d3 += 99;
  std::cout << "d3 == " << d3 << '\n'; 

  std::cout << "d2 <= d3 is " << ((d2<=d3) ? "true" : "false") << '\n';

  return 0;	
}
