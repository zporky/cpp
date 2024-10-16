
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

class Vehicle
{
public:
  Vehicle( std::string l, std::string o, int w = 4) : 
	  license_(l), owner_(o), wheels_(w) { }  
  std::string getLicense() const { return license_; }
  std::string getOwner() const { return owner_; }
  int         getWheels() const { return wheels_; }

  virtual std::string to_string() const;
  ~Vehicle() { std::cout << "Vehicle::~Vehicle" << std::endl; }
private:
  std::string license_;
  std::string owner_;
  int         wheels_;
};
#endif // VEHICLE_H 
