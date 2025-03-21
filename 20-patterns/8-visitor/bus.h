
#ifndef BUS_H
#define BUS_H

#include <string>
#include <memory>
#include "vehicle.h"

class Bus : public Vehicle
{
public:
  Bus( std::string l, std::string o, int w, int p) : 
	  Vehicle(l,o,w), passangers_(p) { }
  int getPassangers() const { return passangers_; }

  virtual std::string to_string() const override;
  virtual std::unique_ptr<Vehicle> clone() const override { 
	  return std::make_unique<Bus>(*this); }
  virtual ~Bus() override { std::cout << "Bus::~Bus()" << std::endl; }

  virtual void accept(VehicleVisitor *visitor) const override 
  {
    visitor->visitBus(*this);	  
  }

private:
  int passangers_;
};

#endif // BUS_H 
