
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

  std::string to_string() const;
  ~Car() { std::cout << "Car::~Car()" << std::endl; }
private:
  double emission_;
};

#endif // CAR_H 
