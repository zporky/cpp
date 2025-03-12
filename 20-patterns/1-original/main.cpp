#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <memory>
#include <string>
#include <sstream>

#include "vehicle.h"
#include "truck.h"
#include "bus.h"
#include "car.h"

void print(const std::unique_ptr<Vehicle>& vp)
{
  std::cout << vp->to_string() << std::endl;
}
int main()
{
  std::list<std::unique_ptr<Vehicle>> vlist;

  std::string input;
  while ( std::getline(std::cin, input ) )
  {
    std::string type;
    std::istringstream is(input);

    is >> type; 
    if ( "car" == type )
    {
      std::string license, owner;      
      int wheels; double emission;
      is >> license >> owner >> wheels >> emission;
      vlist.push_back(std::make_unique<Car>(license, owner, wheels, emission));
    }
    else if ( "bus" == type )
    {
      std::string license, owner;      
      int wheels; int passangers;
      is >> license >> owner >> wheels >> passangers;
      vlist.push_back(std::make_unique<Bus>(license, owner, wheels, passangers));
    }
    else if ( "truck" == type )
    {
      std::string license, owner;      
      int wheels; double weight;
      is >> license >> owner >> wheels >> weight;
      vlist.push_back(std::make_unique<Truck>(license, owner, wheels, weight));
    }
/*
  vlist.push_back( std::make_unique<Bus>("AAA-111", "Bela", 4, 8));
  vlist.push_back( std::make_unique<Truck>("BBB-222", "Dezso", 4, 3.5));
  vlist.push_back( std::make_unique<Car>("ABC-123", "Aladar", 4, 0.5));
  vlist.push_back( std::make_unique<Bus>("CCC-333", "Feri", 6, 10));
  vlist.push_back( std::make_unique<Truck>("DDD-444", "Feri2", 6, 11.5));
  vlist.push_back( std::make_unique<Bus>("EEE-555", "Jozsi", 8, 42));
 */
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
