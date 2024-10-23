/*
    Value vesus behaviour

    Vehicle::identify() was a virtual function in the original version
    of the program, and following that style group() is virtual in the
    revised version. Is a virtual function is the right way to capture 
    the difference between the characteristic strings "car" and "truck"?
    The difference between the derived classes is one of value and not
    behaviour. Objects ofthe derived classes do not behave differently
    nor use different algorithms. A difference in value can be recorded 
    more naturally in a data member than in a virtual function. A data
    member in Vehicle would be sufficient:
 */

#include <iostream>
#include <string>
#include <vector>

class Vehicle
{
public:
    // Vehicle() { }
    Vehicle(std::string g, std::string p = "") : group_(g), plate_(p) { }
    virtual ~Vehicle() { }
    void identify() const {  // non-virtual
	std::cout << group_ << ", plate = " 
		  << (plate_.size() > 0 ? plate_ : "none") << "\n"; 
    }
private:    
    std::string group_;
    std::string plate_;
};

class Car : public Vehicle
{
public:
    Car() : Vehicle("Car") { }
    Car(std::string p) : Vehicle("Car", p) { };
};

class Truck : public Vehicle
{
public:
    Truck() : Vehicle("Truck") { }
    Truck(std::string p) : Vehicle("Truck", p) { };
};

class Garage
{
public:
    Garage(int max);

    int       accept(Vehicle*);
    Vehicle  *release(int bay);
    void      listVehicles() const;
private:
    int                    maxVehicles_;
    std::vector<Vehicle *> parked_;
};

Garage::Garage(int max) : maxVehicles_(max) 
{
    parked_.resize(maxVehicles_);
}

int Garage::accept(Vehicle *veh)
{
  for( int bay = 0; bay < maxVehicles_; ++bay )
      if( !parked_[bay] )
      {
          parked_[bay] = veh;
          return bay;
      }
  return( -1 );       // No free bay
}

Vehicle *Garage::release(int bay)
{
    if( bay < 0 || bay > maxVehicles_ )
        return nullptr;
    Vehicle *veh = parked_[bay];
    parked_[bay] = nullptr;
    return veh ;
}

void Garage::listVehicles() const
{
    for( int bay = 0; bay < maxVehicles_; ++bay )
        if( parked_[bay] )
        {
            std::cout << "Vehicle in bay " <<  bay << " is ";
            parked_[bay]->identify();
        }
}

Car c1{"AAA100"};
Car c2{"BBB200"};
Car c3{"CCC300"};

Truck t1{"TTT999"};
Truck t2{"SSS888"};
Truck t3{"UUU777"};
Truck t4{};  // still works


int main( )
{
    Garage Park{14};

    Park.accept(&c1);
    int t2bay = Park.accept(&t2);
    Park.accept(&c3);
    Park.accept(&t2);
    Park.accept(&t4);

    Park.release(t2bay);

    Park.listVehicles();

    return 0;
}

/*
 
   The output of the program is the following:

Vehicle in bay 0 is Car, plate = AAA100
Vehicle in bay 2 is Car, plate = CCC300
Vehicle in bay 3 is Truck, plate = SSS888
Vehicle in bay 4 is Truck, plate = none

 */
