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

  List::Iterator it = l.begin();
  while ( l.end() !=  it ) 
  {
    std::cout << *it << " ";
    ++it;
  }

  return 0;
}


