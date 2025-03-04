#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "creator.h"

std::unique_ptr<Vehicle> Creator::create( std::string input)
{
  std::string type;
  std::istringstream is(input);

  is >> type; 
  return map_[type]->create(input);
}
