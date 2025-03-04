#include <string>
#include <sstream>

#include "vehicle.h"

std::string Vehicle::to_string() const
{
  std::ostringstream os;
  os << "[ Vehicle: l=" << getLicense() 
	                << ", o=" << getOwner()
			<< ", w=" << getWheels() << " ]";
  return os.str();  
}
