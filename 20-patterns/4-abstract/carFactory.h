
#ifndef CAR_FACTORY_H
#define CAR_FACTORY_H

#include <memory>
#include <string>

#include "vehicleFactory.h"
#include "car.h"

class CarFactory : public VehicleFactory
{
public: 	
  virtual std::unique_ptr<Vehicle> create( std::string input) const override;
};

#endif  // CAR_FACTORY_H



