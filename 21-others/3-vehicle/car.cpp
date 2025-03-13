#include "etl/to_string.h"
#include "car.h"

etl::string<80> Car::to_string() const
{
  etl::string<20> e;
  etl::to_string( getEmission(), e, etl::format_spec().precision(6));  
  etl::string<80> ret = "[ Car = ";
 	ret += Vehicle::to_string();
        ret += ", emission= ";
        ret += e;
        ret += " ]";
  return ret;
}

