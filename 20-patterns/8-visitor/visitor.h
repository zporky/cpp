#ifndef VISITOR_H
#define VISITOR_H

class Bus;
class Car;
class Truck;

class VehicleVisitor
{
public:	
  virtual void visitBus(const Bus &b) const = 0; 	
  virtual void visitCar(const Car &c) const = 0; 	
  virtual void visitTruck(const Truck &t) const = 0; 	
};

#endif // VISITOR_H
