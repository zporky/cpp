
#include <iostream>

auto divide( int x, int y)
{
  auto ratio = x/y;
  auto reminder = x%y;

  return std::pair{ratio, reminder};  
}

int main()
{
  double x, y;

  while ( std::cin >> x >> y )
  {
    auto [ a, b ] = divide( x, y);
    std::cout << a << ' ' << b << '\n';    
  }
}
