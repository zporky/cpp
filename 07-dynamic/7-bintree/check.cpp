
#include <iostream>

int main()
{
  int prev = -1;  /* ensure that the first number is ok */
  int curr;

  while ( std::cin >> curr)
  {
    if ( curr < prev )	  /* inversion!!! */
    {
      std::cerr << "Inversion: " << prev << " > " << curr << '\n';
    }
    prev = curr;    
  }  
  return 0;	
}
