
#ifndef BUS_H
#define BUS_H

#include <string>
#include "vehicle.h"

class Bus : public Vehicle
{
public:
  Bus( std::string l, std::string o, int w, int p) : 
	  Vehicle(l,o,w), passangers_(p) { }
  int getPassangers() const { return passangers_; }

  std::string to_string() const;
  ~Bus() { std::cout << "Bus::~Bus()" << std::endl; }
private:
  int passangers_;
};

#endif // BUS_H 
