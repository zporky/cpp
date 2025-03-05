
#ifndef CAR_H
#define CAR_H

#include <string>
#include <memory>
#include "vehicle.h"

class Car : public Vehicle
{
public:
  Car( std::string l, std::string o, int w, double e) : 
	  Vehicle(l,o,w), emission_(e) { }
  double getEmission() const { return emission_; }

  virtual std::string to_string() const override;
  virtual std::unique_ptr<Vehicle> clone() const override { 
	  return std::make_unique<Car>(*this); }
  virtual ~Car() override { std::cout << "Car::~Car()" << std::endl; }

  virtual void accept(VehicleVisitor *visitor) const override 
  {
    visitor->visitCar(*this);	  
  }
private:
  double emission_;
};

#endif // CAR_H 
