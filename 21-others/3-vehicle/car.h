
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle
{
public:
  Car( etl::string<20> l, etl::string<20> o, int w, double e) : 
	  Vehicle(l,o,w), emission_(e) { }
  double getEmission() const { return emission_; }

  virtual etl::string<80> to_string() const override;
  virtual ~Car() override { std::cout << "Car::~Car()" << std::endl; }
private:
  double emission_;
};

#endif // CAR_H 
