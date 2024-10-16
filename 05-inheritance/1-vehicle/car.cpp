
#include <string>
#include <sstream>
#include "car.h"

std::string Car::to_string() const
{
  std::ostringstream os;
  os << "[ Car = " << Vehicle::to_string() 
     << ", emission= " << getEmission() << " ]";
  return os.str();
}

