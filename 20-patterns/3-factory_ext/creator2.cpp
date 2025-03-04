#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "creator2.h"
#include "vehicle.h"
#include "truck.h"
#include "bus.h"
#include "car.h"
#include "tractor.h"

std::unique_ptr<Vehicle> Creator2::create( std::string input) const 
{
  std::string type;
  std::istringstream is(input);

  is >> type; 
  if ( "car" == type )
  {
    std::string license, owner;      
    int wheels; double emission;
    is >> license >> owner >> wheels >> emission;
    return std::make_unique<Car>(license, owner, wheels, 0); // Fix
  }
  else if ( "bus" == type )
  {
    std::string license, owner;      
    int wheels; int passangers;
    is >> license >> owner >> wheels >> passangers;
    return std::make_unique<Bus>(license, owner, wheels, passangers);
  }
  else if ( "truck" == type )
  {
    std::string license, owner;      
    int wheels; double weight;
    is >> license >> owner >> wheels >> weight;
    return std::make_unique<Truck>(license, owner, wheels, weight);
  }
  else if ( "tractor" == type )
  {
    std::string license, owner;      
    int wheels; 
    is >> license >> owner >> wheels;
    return std::make_unique<Tractor>(license, owner, wheels);    	  
  }
  return nullptr;
}
