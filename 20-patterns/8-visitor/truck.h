
#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <memory>
#include "vehicle.h"

class Truck : public Vehicle
{
public:
  Truck( std::string l, std::string o, int w, double g) : 
	  Vehicle(l,o,w), weight_(g) { }
  double getWeight() const { return weight_; }

  virtual std::string to_string() const override;
  virtual std::unique_ptr<Vehicle> clone() const override { 
	  return std::make_unique<Truck>(*this); }
  virtual ~Truck() override { std::cout << "Truck::~Truck()" << std::endl; }

  virtual void accept(VehicleVisitor *visitor) const override 
  {
    visitor->visitTruck(*this);	  
  }

private:
  double weight_;
};

#endif // TRUCK_H 
