#ifndef SIZE_H
#define SIZE_H

#include "visitor.h"

class Size : public VehicleVisitor
{
  virtual void visitBus(const Bus &b) const override
  {
    std::cout << b.getLicense() << ", Bus, size = " 
	      << sizeof(b) 
	      << '\n';    	    
  } 
  virtual void visitCar(const Car &c) const override
  {
    std::cout << c.getLicense() << ", Car, size = "
	      << sizeof(c)
	      << '\n';    	    
  }
  virtual void visitTruck(const Truck &t) const override
  {
    std::cout << t.getLicense() << ", Truck, size = "
	      << sizeof(t)
	      << '\n';    	    
  }

};

#endif // SIZE_H
