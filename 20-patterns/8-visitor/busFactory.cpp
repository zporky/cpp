#include <sstream>
#include "busFactory.h"

std::unique_ptr<Vehicle> BusFactory::create( std::string input) const
{
   std::istringstream is{input};	
   std::string type, license, owner;      
   int wheels; int passangers;
   is >> type >> license >> owner >> wheels >> passangers;
   return std::make_unique<Bus>(license, owner, wheels, passangers);
}
