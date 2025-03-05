
#ifndef TRUCK_FACTORY_H
#define TRUCK_FACTORY_H

#include <memory>
#include <string>

#include "vehicleFactory.h"
#include "truck.h"

class TruckFactory : public VehicleFactory
{
public: 	
  virtual std::unique_ptr<Vehicle> create( std::string input) const override;
};

#endif  // TRUCK_FACTORY_H



