#include <iostream>
#include "vec.h"

int main()
{
  Vec  v;
  int  inp;
  
  // read bufsize elements
  while ( std::cin >> inp )
  {
    v.push_back(inp);	  
  }
 
  // print elements in reverse order 
  for ( int i = v.size()-1; i >= 0; --i)
  {
    std::cout << v[i] << (i==0?"\n":", "); 
  }
  // print and remove element 
  while ( !v.empty() )
  {
    std::cout << v.back();
    v.pop_back();
    std::cout << (v.empty()?"\n":", "); 
  }
  return 0;
}


