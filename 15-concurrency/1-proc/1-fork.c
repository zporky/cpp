
#include <iostream>
#include <unistd.h>

int main()
{
  for(int i = 0; i < 3; ++i)
  {
    std::cout << '.' ;
    fork();    
  }	  
}
