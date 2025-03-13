
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "etl/string.h"

class Vehicle
{
public:
  Vehicle( etl::string<20> l, etl::string<20> o, int w = 4) : 
		  license_(l), owner_(o), wheels_(w) { }  
  etl::string<20> getLicense() const { return license_; }
  etl::string<20> getOwner() const { return owner_; }
  int             getWheels() const { return wheels_; }

  virtual etl::string<80> to_string() const = 0;
  virtual ~Vehicle() { std::cout << "Vehicle::~Vehicle" << std::endl; }
//  virtual std::unique_ptr<Vehicle> clone() const = 0;
private:
  etl::string<20> license_;
  etl::string<20> owner_;
  int             wheels_;
};
#endif // VEHICLE_H 
