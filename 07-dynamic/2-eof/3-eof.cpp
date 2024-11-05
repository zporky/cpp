#include <iostream>

int main()
{
  const int bufsize = 16;
  int buffer[bufsize];
  int i = 0;
  // read bufsize elements
  for ( ; i < bufsize && std::cin >> buffer[i]; ++i)
  {
    ;
  }
 
  // print elements in reverse order - wrong
  for ( ; i >= 0; --i)
  {
    std::cout << buffer[i] << (i==0?"\n":", "); 
  }
  return 0;
}


