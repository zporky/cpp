#include <iostream>

int main()
{
  const int bufsize = 16;
  int buffer[bufsize];
  
  // read bufsize elements
  for ( int i = 0; i < bufsize; ++i)
  {
    std::cin >> buffer[i];
  }
 
  // print elements in reverse order
  for ( int i = bufsize-1; i >= 0; --i)
  {
    std::cout << buffer[i] << (i==0?"\n":", "); 
  }
  return 0;
}


