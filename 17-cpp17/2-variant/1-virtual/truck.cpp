
#include <string>
#include <sstream>
#include "truck.h"

std::string Truck::to_string() const
{
  std::ostringstream os;
  os << "[ Truck = " << Vehicle::to_string() 
     << ", weight= " << getWeight() << " ]";
  return os.str();
}

