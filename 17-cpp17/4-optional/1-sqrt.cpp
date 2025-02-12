
#include <iostream>
#include <cmath>
#include <optional>

std::optional<double> sqrt2(double x) 
{
  if ( x < 0.0 )
    return {};
  else
    return std::sqrt(x);  
}

int main()
{
  double d;
  while ( std::cin >> d )
  {
    auto res = sqrt2(d);
    if ( res.has_value() )
      std::cout << res.value() << '\n';
    else 
      std::cout << "invalid argument\n";	    
  }  
}


