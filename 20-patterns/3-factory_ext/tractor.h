
#ifndef TRACTOR_H
#define TRACTOR_H

#include <string>
#include <memory>
#include "vehicle.h"

class Tractor : public Vehicle
{
public:
  Tractor( std::string l, std::string o, int w) : 
	  Vehicle(l,o,w) { }

  virtual std::string to_string() const override;
  virtual std::unique_ptr<Vehicle> clone() const override { 
	  return std::make_unique<Tractor>(*this); }
  virtual ~Tractor() override { std::cout << "Tractor::~Tractor()" << std::endl; }
private:
};

#endif // TRACTOR_H 
