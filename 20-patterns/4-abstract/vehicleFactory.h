
#ifndef VEHICLE_FACTORY_H
#define VEHICLE_FACTORY_H

#include <memory>
#include <string>

#include "vehicle.h"

class VehicleFactory
{
public: 	
  virtual std::unique_ptr<Vehicle> create( std::string input) const = 0;
};

#endif  // VEHICLE_FACTORY_H



