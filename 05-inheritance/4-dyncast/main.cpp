#include <iostream>
#include <list>
#include <algorithm>

#include "vehicle.h"
#include "truck.h"
#include "bus.h"
#include "car.h"

void print(Vehicle *p)
{
  std::cout << p->to_string() << std::endl;
}
int main()
{
  std::list<Vehicle*> vlist;
  vlist.push_back( new Bus("AAA-111", "Bela", 4, 8));
  vlist.push_back( new Truck("BBB-222", "Dezso", 4, 3.5));
  vlist.push_back( new Car("ABC-123", "Aladar", 4, 0.5));
  vlist.push_back( new Bus("CCC-333", "Feri", 6, 10));
  vlist.push_back( new Truck("DDD-444", "Feri2", 6, 11.5));
  vlist.push_back( new Bus("EEE-555", "Jozsi", 8, 42));

  std::vector<Vehicle*> vvec;
  for ( auto i = vlist.begin(); i != vlist.end(); ++i)
  {
    Vehicle *vp = *i;
    if ( Truck *tp = dynamic_cast<Truck*>(vp) )
    { 
      Truck t = *tp;
      vvec.push_back(new Truck(t)); 
    }
    else if ( Bus *bp = dynamic_cast<Bus*>(vp) )
    {
      Bus b = *bp;
      vvec.push_back(new Bus(b));
    }
    else if ( Car *cp = dynamic_cast<Car*>(vp) )
    {
      Car c = *cp;
      vvec.push_back(new Car(c));
    }
  }
  for_each ( vlist.begin(), vlist.end(), print); 
  std::cout << "================================" << '\n';
  for_each ( vvec.begin(), vvec.end(), print); 
  std::cout << "================================" << '\n';
  for_each ( vlist.begin(), vlist.end(), [](Vehicle *p) { delete p; } );
  std::cout << "================================" << '\n';
  for_each ( vvec.begin(), vvec.end(), [](Vehicle *p) { delete p; } );

  return 0;
}
