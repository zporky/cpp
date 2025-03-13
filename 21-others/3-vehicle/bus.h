
#ifndef BUS_H
#define BUS_H

#include "vehicle.h"

class Bus : public Vehicle
{
public:
  Bus( etl::string<20> l, etl::string<20> o, int w, int p) : 
	  Vehicle(l,o,w), passangers_(p) { }
  int getPassangers() const { return passangers_; }

  virtual etl::string<80> to_string() const override;
  virtual ~Bus() override { std::cout << "Bus::~Bus()" << std::endl; }
private:
  int passangers_;
};

#endif // BUS_H 
