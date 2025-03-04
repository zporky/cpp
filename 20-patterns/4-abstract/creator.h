#ifndef CREATOR_H
#define CREATOR_H

#include <memory>
#include <string>
#include <map>

#include "vehicle.h"
#include "carFactory.h"
#include "truckFactory.h"
#include "busFactory.h"

class Creator
{
public:
  std::unique_ptr<Vehicle> create( std::string input);
private:
  std::map<std::string, VehicleFactory*>  map_ = {
	  { "bus",   new BusFactory{}   },  
	  { "car",   new CarFactory{}   },  
	  { "truck", new TruckFactory{} }  
  };
};

#endif // CREATOR_H
