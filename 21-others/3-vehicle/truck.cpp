#include "etl/to_string.h"
#include "truck.h"

etl::string<80> Truck::to_string() const
{
  etl::string<20> w;
  etl::to_string( getWeight(), w, etl::format_spec().precision(6));
  etl::string<80> ret = "[ Truck = ";
 	ret += Vehicle::to_string();
        ret += ", weight= ";
        ret += w;
        ret += " ]";
  return ret;
}

