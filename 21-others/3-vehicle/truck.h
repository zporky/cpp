
#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

class Truck : public Vehicle
{
public:
  Truck( etl::string<20> l, etl::string<20> o, int w, double g) : 
	  Vehicle(l,o,w), weight_(g) { }
  double getWeight() const { return weight_; }

  virtual etl::string<80> to_string() const override;
  virtual ~Truck() override { std::cout << "Truck::~Truck()" << std::endl; }
private:
  double weight_;
};

#endif // TRUCK_H 
