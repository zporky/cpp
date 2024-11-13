
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char **argv)
{
  int i;
  int max = 100000; /* number of elements by default */

  if ( argc > 1 ) /* if command line argument is given */
  {
    int imax = std::stoi(argv[1], nullptr);  /* converts to int */
    if ( imax > 0 )   /* if argv[1] was meaningful */
      max = imax;
  }    
//  srand(time(NULL));   /* seeding the random generator */
  for ( i = 0; i < max; ++i)
    std::cout << std::rand() << " ";  /* int between 0..MAXINT */

  return 0;
}
