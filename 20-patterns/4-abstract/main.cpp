#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>
#include <string>

#include "creator.h"
#include "vehicle.h"
// #include "truck.h"
// #include "bus.h"
// #include "car.h"

void print(const std::unique_ptr<Vehicle>& vp)
{
  std::cout << vp->to_string() << std::endl;
}
int main()
{
  std::list<std::unique_ptr<Vehicle>> vlist;

  Creator::get()->print();
  
  std::string input;
  while ( std::getline(std::cin, input ) )
  {
    vlist.push_back(Creator::get()->create(input));
  }

  std::vector<std::unique_ptr<Vehicle>> vvec;
  for ( auto i = vlist.begin(); i != vlist.end(); ++i)
  {
    vvec.push_back( (*i)->clone() );
  }
  for_each ( vlist.begin(), vlist.end(), print); 
  std::cout << "================================" << '\n';
  for_each ( vvec.begin(), vvec.end(), print); 
  std::cout << "================================" << '\n';

  return 0;
}
