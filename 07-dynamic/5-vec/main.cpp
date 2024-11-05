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
 
  Vec v2{v};
  // print and remove element 
  while ( !v2.empty() )
  {
    std::cout << v2.back();
    v2.pop_back();
    std::cout << (v2.empty()?"\n":", "); 
  }
  Vec v3{std::move(v)};
  // print elements in reverse order 
  for ( int i = v.size()-1; i >= 0; --i)
  {
    std::cout << v[i] << (i==0?"\n":", "); 
  }
  for ( int i = v3.size()-1; i >= 0; --i)
  {
    std::cout << v3[i] << (i==0?"\n":", "); 
  }

  return 0;
}


