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
  
  if ( "tractor" == type )
  {
    std::string license, owner;      
    int wheels; 
    is >> license >> owner >> wheels;
    return std::make_unique<Tractor>(license, owner, wheels);    	  
  }
  return Creator::create( input );
}
