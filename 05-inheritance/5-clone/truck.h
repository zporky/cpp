
#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "vehicle.h"

class Truck : public Vehicle
{
public:
  Truck( std::string l, std::string o, int w, double g) : 
	  Vehicle(l,o,w), weight_(g) { }
  double getWeight() const { return weight_; }

  virtual std::string to_string() const override;
  virtual Truck *clone() const override { return new Truck(*this); }
  virtual ~Truck() override { std::cout << "Truck::~Truck()" << std::endl; }
private:
  double weight_;
};

#endif // TRUCK_H 
