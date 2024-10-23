/*
     In the hardware store example, we examined the class relationships,
    and the difference between variability in behaviour and value.  In 
    that example, not all the inheritance relationships was verified.

    In the following example inheritance relationships are "natural", 
    and public inheritance is appropriate. However, the decision to use 
    public inheritance raises other questions with respect to the detailed 
    distribution of the and function members of the classes in the 
    inheritance hierarchy.


    C++ Style
    Example 2


    Vehicles and garages

    The program manipulates vehicles, recording their entry and exit
    from a parking garage. Classes Car and Truck are derived from a
    common base class, Vehicle. The inheritance hierarchy is shown here:

                         Vehicle

                          /   \
                         /     \
             
                      Car     Truck

    Vehicles identify themselves by printing a message with the vehicle's
    type (car or truck) and license plate number.

    The main function exercises the Garage class by inserting and removing
    Truck and Car objects from a Garage called Park. The public interface 
    to class Garage is defined in terms of pointers to Vehicle objects.

    Note that Garage is more than just a bounded collection of pointers
    to Vehicle. Each vehicle registered in the garage has an associated 
    bay number, the only key by which it may be referred to within the 
    Garage.


    Questions:
      - Which members should be public, private or protected?
      - Which functions should be virtual? 
      - There is a serious bug in the interaction between the base class
        and the derived class. Find it and fix it.

    Read the program, and make suggestions to create better coupling
    between classes. 

 */

#include <iostream>
#include <string>
#include <vector>

class Vehicle
{
public:
    Vehicle() { }
    Vehicle(std::string p) : plate_(p) { }
   ~Vehicle() { }
    virtual void identify() const { 
	std::cout << "Vehicle\n"; 
    }
protected:
    std::string plate_;
};

class Car : public Vehicle
{
public:
    Car() : Vehicle() { }
    Car(std::string p) : Vehicle(p) { };
    virtual void identify() const override { 
	std::cout << "Car, plate = " << plate_ << "\n"; 
    }
};

class Truck : public Vehicle
{
public:
    Truck() : Vehicle() { }
    Truck(std::string p) : Vehicle(p) { };
    virtual void identify() const override { 
	std::cout << "Truck, plate = " << plate_ << "\n"; 
    }
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

Car c1("AAA100");
Car c2("BBB200");
Car c3("CCC300");

Truck t1("TTT999");
Truck t2("SSS888");
Truck t3("UUU777");


int main( )
{
    Garage Park{14};

    Park.accept(&c1);
    int t2bay = Park.accept(&t2);
    Park.accept(&c3);
    Park.accept(&t2);

    Park.release(t2bay);

    Park.listVehicles();

    return 0;
}

/*
 
   The output of the program is the following:

Vehicle in bay 0 is Car, plate = AAA100
Vehicle in bay 2 is Car, plate = CCC300
Vehicle in bay 3 is Truck, plate = SSS888

 */
