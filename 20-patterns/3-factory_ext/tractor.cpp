
#include <string>
#include <sstream>
#include "tractor.h"

std::string Tractor::to_string() const
{
  std::ostringstream os;
  os << "[ Tractor = " << Vehicle::to_string(); 
  return os.str();
}

