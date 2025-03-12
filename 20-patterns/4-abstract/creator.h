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
  static Creator *get();
  std::unique_ptr<Vehicle> create( std::string input);
  int add( std::string key, VehicleFactory *value) { map_[key] = value; return 0; }
  void print() { for ( auto [k,v] : map_) std::cout << k << '\n';}
private:
  static Creator *pinstance_;
  std::map<std::string, VehicleFactory*>  map_;
};

#endif // CREATOR_H
