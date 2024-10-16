
#include <string>
#include <sstream>
#include "bus.h"

std::string Bus::to_string() const
{
  std::ostringstream os;
  os << "[ Bus = " << Vehicle::to_string() 
     << ", pass= " << getPassangers() << " ]";
  return os.str();
}

