
#ifndef BUS_FACTORY_H
#define BUS_FACTORY_H

#include <memory>
#include <string>

#include "vehicleFactory.h"
#include "bus.h"

class BusFactory : public VehicleFactory
{
public: 	
  virtual std::unique_ptr<Vehicle> create( std::string input) const override;
};

#endif  // BUS_FACTORY_H



