#include <iostream>

int main()
{
  int  capacity = 4;
  int  size = 0;   
  int *buffer = new int[capacity];
  int  inp;
  
  // read bufsize elements
  while ( std::cin >> inp )
  {
    if ( capacity == size )
    {
      int *ptr = new int[2*capacity];
      capacity *= 2;
      for ( int i = 0; i < size; ++i)
      {
        ptr[i] = buffer[i];	      
      }
      delete [] buffer;
      buffer = ptr;
    }	    
    buffer[size++] = inp;
  }
 
  // print elements in reverse order 
  for ( int i = size-1; i >= 0; --i)
  {
    std::cout << buffer[i] << (i==0?"\n":", "); 
  }
  delete [] buffer;
  return 0;
}


