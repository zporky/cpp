
#include <algorithm>
#include <vector>
#include <iostream>
#include "date.h"

struct month_beg_t
{
  bool operator()(date d)
  {
    return d.getDay() < 5;
  }
};

int main()
{
  std::vector<date> v;
  v.push_back(date(1990,12,4));
  v.push_back(date(1999,2,24));
  v.push_back(date(2001,1,1));
  v.push_back(date(2014,8,30));

  std::vector<date>::const_iterator it1 = 
               std::find( v.begin(), v.end(), date(2001));
  if ( v.end() != it1 )
  {
    std::cout << *it1 << std::endl;
  }
  std::cout << "-----------------------" << std::endl;

  for ( std::vector<date>::iterator it2 = 
                 std::find_if( v.begin(), v.end(), month_beg_t() ); 
        v.end() != it2;
        it2 = std::find_if( it2+1, v.end(), month_beg_t() )) 
  {
    std::cout << *it2 << std::endl;
    
  }
  return 0;
}

