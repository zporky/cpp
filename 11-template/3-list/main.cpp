#include <iostream>
#include <string>
#include "list.h"

int main()
{
  List<std::string>  l;
  std::string        inp;
  
  // read bufsize elements
  while ( std::cin >> inp )
  {
    l.push_back(inp);	  
  }
  std::cout << "l.size = "  <<  l.size() << '\n'; 

  List<std::string>::Iterator it = l.begin();
  while ( l.end() !=  it ) 
  {
    std::cout << *it << " ";
    ++it;
  }

  return 0;
}


