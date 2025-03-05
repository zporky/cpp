#include <sstream>
#include "carFactory.h"

std::unique_ptr<Vehicle> CarFactory::create( std::string input) const
{
    std::istringstream is{input};	
    std::string license, owner;      
    int wheels; double emission;
    is >> license >> owner >> wheels >> emission;
    return std::make_unique<Car>(license, owner, wheels, emission);
}
