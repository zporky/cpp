#ifndef CREATOR2_H
#define CREATOR2_H

#include <memory>
#include <string>

#include "vehicle.h"
#include "creator.h"

class Creator2 : public Creator
{
public:
  virtual std::unique_ptr<Vehicle> create( std::string input) const override;	
};

#endif // CREATOR2_H
