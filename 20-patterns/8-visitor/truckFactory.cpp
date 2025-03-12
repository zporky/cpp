#include <sstream>
#include "truckFactory.h"

std::unique_ptr<Vehicle> TruckFactory::create( std::string input) const
{
    std::istringstream is{input};
    std::string type, license, owner;      
    int wheels; double weight;
    is >> type >> license >> owner >> wheels >> weight;
    return std::make_unique<Truck>(license, owner, wheels, weight);
}
