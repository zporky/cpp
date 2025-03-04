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

  std::string license, owner;      
  int wheels; 
  
  is >> type >> license >> owner >> wheels; 

  if ( "car" == type )
  {
    double emission;
    is >> emission;
    return std::make_unique<Car>(license, owner, wheels, emission);
  }
  else if ( "bus" == type )
  {
    int passangers;
    is >> passangers;
    return std::make_unique<Bus>(license, owner, wheels, passangers);
  }
  else if ( "truck" == type )
  {
    double weight;
    is >> weight;
    return std::make_unique<Truck>(license, owner, wheels, weight);
  }
  return nullptr;
}
