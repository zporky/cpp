
#include <iostream>	// standard header files

#include "date.h"	// date.h for date class

int main()
{

  // date d;	// syntax error: no default constructor

  date d(1);
  while ( std::cin >> d )  // read date until eof
  {
    d += 40;	// add 40 days
    std::cout << d << std::endl; // print result 
  }
  std::cin.clear(); // clear eof()
  
  date d2( 2015, 3);  // this should be 2015.03.01
  d = d2;	// assignment, now d is 2015.03.01
  std::cout << d << " == " << d2 << std::endl;

  date d3("2015.03.23");
  std::cout << "d3++ == " << d3++ << std::endl;
  std::cout << " d3  == " <<  d3  << std::endl;
  std::cout << "++d3 == " << ++d3 << std::endl;
  std::cout << " d3  == " <<  d3  << std::endl;

  d3.setDate(2000,1,1);
  std::cout << "d3.setDate(2000,1,1) == " << d3 << std::endl;
  d3.setYear(2015).setMonth(3).setDay(23);
  std::cout << "d3 == " << d3 << std::endl;

  std::string s; 
  while( std::cin >> s )   
  {
    try 
    {
      std::cout << s << " == ";
      date d4(s.c_str());    // test constructor from char*
      std::cout << d4 << std::endl;
    }
    catch( std::exception& e )   // catch exception
    {
      std::cerr << e.what() << std::endl;  // what() is inherited from 
                                           // std::exception
    }
  }

  return 0;
}


