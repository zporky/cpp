#include <iostream>
#include "list.h"

int main()
{
  List  l;
  int   inp;
  
  // read bufsize elements
  while ( std::cin >> inp )
  {
    l.push_back(inp);	  
  }
  std::cout << "l.size = "  <<  l.size() << '\n'; 
  
  List l2{l};
  std::cout << "l.size = "  <<  l.size() << '\n'; 
  std::cout << "l2.size = " << l2.size() << '\n'; 

  while ( !l.empty() )
  {
    std::cout << l.back();
    l.pop_back();
    std::cout << (l.empty()?"\n":", "); 
  }
  std::cout << "l.size = " << l.size() << '\n'; 
  while ( !l2.empty() )
  {
    std::cout << l2.back();
    l2.pop_back();
    std::cout << (l2.empty()?"\n":", "); 
  }
  std::cout << "l2.size = " << l2.size() << '\n'; 

  return 0;
}


