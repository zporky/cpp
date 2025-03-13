#include "etl/string.h"
#include "etl/string_stream.h"
#include "etl/to_string.h"

#include "vehicle.h"

etl::string<80> Vehicle::to_string() const
{
  etl::string<20> w;
  etl::to_string( getWheels(), w, etl::format_spec().width(4));  
  etl::string<80> ret = "Vehicle: l=";
        ret += getLicense();
        ret += ", o=";
        ret += getOwner();
	ret += ", w=";
        ret += w;
        ret += " ]";
  return ret;
}
