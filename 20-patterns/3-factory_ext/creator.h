#ifndef CREATOR_H
#define CREATOR_H

#include <memory>
#include <string>

#include "vehicle.h"

class Creator
{
public:
  virtual std::unique_ptr<Vehicle> create( std::string input) const;	
};

#endif // CREATOR_H
