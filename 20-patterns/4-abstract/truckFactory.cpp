#include <sstream>
#include "truckFactory.h"

std::unique_ptr<Vehicle> TruckFactory::create( std::string input) const
{
    std::istringstream is{input};
    std::string license, owner;      
    int wheels; double weight;
    is >> license >> owner >> wheels >> weight;
    return std::make_unique<Truck>(license, owner, wheels, weight);
}
