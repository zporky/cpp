#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "creator.h"
#include "vehicle.h"
#include "truck.h"
#include "bus.h"
#include "car.h"

std::unique_ptr<Vehicle> Creator::create( std::string input) const
{
  std::string type;
  std::istringstream is(input);

  is >> type; 
  if ( "car" == type )
  {
    std::string license, owner;      
    int wheels; double emission;
    is >> license >> owner >> wheels >> emission;
    return std::make_unique<Car>(license, owner, wheels, emission);
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
  return nullptr;
}
