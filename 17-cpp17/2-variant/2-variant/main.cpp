#include <iostream>
#include <list>
#include <algorithm>
#include <variant>

#include "vehicle.h"
#include "truck.h"
#include "bus.h"
#include "car.h"

using Vehicles = std::variant<Car, Bus, Truck>;

void print(const Vehicles& v)
{
  std::visit( [](auto&& arg) {	
       std::cout << arg.to_string() << std::endl;
     }, v);
}
int main()
{
  std::list<Vehicles> vlist;
  vlist.push_back( Bus{"AAA-111", "Bela", 4, 8});
  vlist.push_back( Truck{"BBB-222", "Dezso", 4, 3.5});
  vlist.push_back( Car{"ABC-123", "Aladar", 4, 0.5});
  vlist.push_back( Bus{"CCC-333", "Feri", 6, 10});
  vlist.push_back( Truck{"DDD-444", "Feri2", 6, 11.5});
  vlist.push_back( Bus{"EEE-555", "Jozsi", 8, 42});

  std::vector<Vehicles> vvec;
  for ( auto i = vlist.begin(); i != vlist.end(); ++i)
  {
    vvec.push_back( *i );
  }
  for_each ( vlist.begin(), vlist.end(), print); 
  std::cout << "================================" << '\n';
  for_each ( vvec.begin(), vvec.end(), print); 
  std::cout << "================================" << '\n';

  return 0;
}
