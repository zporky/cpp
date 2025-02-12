#include <iostream>

auto factorial( int n)
{
  if ( n < 2 )
    return 1;
  else
    return n * factorial(n-1);
}

int main()
{
  std::cout << factorial(12) << '\n';	
}
