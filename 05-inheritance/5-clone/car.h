
#ifndef CAR_H
#define CAR_H

#include <string>
#include "vehicle.h"

class Car : public Vehicle
{
public:
  Car( std::string l, std::string o, int w, double e) : 
	  Vehicle(l,o,w), emission_(e) { }
  double getEmission() const { return emission_; }

  virtual std::string to_string() const override;
  virtual Car *clone() const override { return new Car(*this); }
  virtual ~Car() override { std::cout << "Car::~Car()" << std::endl; }
private:
  double emission_;
};

#endif // CAR_H 
