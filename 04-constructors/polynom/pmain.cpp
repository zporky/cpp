#include <iostream>
#include "polynom.h"

int main()
{
  std::vector<Polynom>  polynoms{ 
	  {{    -2, 0, 5,-3, 8 }},
	  {{ 42, 0, 5, 0, 8, 9 }},
	  {{-42, 0, 5, 0, 8,-9 }},
	  {{  0, 0, 5, 0, 8,-9 }},
	  {{  0, 0,-5, 0, 8,-9 }},
	  {{  8 }},
	  {{ -8 }},
	  {{ 0 }},
	  {{   }}
  };
  polynoms.push_back( Polynom{} ); // default constructor
  
  int t1 = -2;
  int t2 =  0;
  int t3 = 42;
  for ( auto poly : polynoms )
  {
    std::string s = poly.to_string();
    std::cout << s << "\t\t";
    std::cout << "deg = " << poly.deg() << "\t\t";
    for ( int i = 9; i >= 0; --i )
    {
      std::cout << poly[i] << " ";	    
    }	    
    std::cout << "\neval(" << t1 << ") == " << poly(t1);
    std::cout << "\teval(" << t2 << ") == " << poly(t2);
    std::cout << "\teval(" << t3 << ") == " << poly(t3);
    std::cout << '\n';
  }
  return 0;
}

