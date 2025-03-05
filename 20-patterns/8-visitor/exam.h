#ifndef EXAM_H
#define EXAM_H

#include "visitor.h"

class Exam : public VehicleVisitor
{
  virtual void visitBus(const Bus &b) const override
  {
    std::cout << b.getLicense() 
	      << ( b.getPassangers() < 10 ? " passed" : " failed")
	      << '\n';    	    
  } 
  virtual void visitCar(const Car &c) const override
  {
    std::cout << c.getLicense() 
	      << ( c.getEmission() < 1.0 ? " passed" : " failed")
	      << '\n';    	    
  }
  virtual void visitTruck(const Truck &t) const override
  {
    std::cout << t.getLicense() 
	      << ( t.getWeight() / t.getWheels() < 1.0 ? " passed" : " failed")
	      << '\n';    	    
  }

};

#endif // EXAM_H
