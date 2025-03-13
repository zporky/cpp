#include "etl/to_string.h"
#include "bus.h"

etl::string<80> Bus::to_string() const
{
  etl::string<20> p;
  etl::to_string( getPassangers(), p, etl::format_spec().width(3));
  etl::string<80> ret = "[ Bus = ";
 	ret += Vehicle::to_string(); 
     	ret += ", pass= ";
        ret += p;
        ret += " ]";
  return ret;
}

