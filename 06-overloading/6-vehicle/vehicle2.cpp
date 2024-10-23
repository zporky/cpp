/*
    Consistency is fundamental in class design and implementation.
    We can speak about external consistency (in the interface) and
    internal consistency (in the implementation of each objects state.

    When inheritance is used, there is a further issue of consistency
    to consider: consistency in the interface between a base class and
    its derived classes. In addition to the public interface, a base
    class may have a protected interface consisting of the protected
    members accessible from derived classes. By declaring protected
    members, a base class provides special access for use by its derived
    classes. The derived classes must use this access consistently with
    the implementation of the base class.

    Car and Truck make inconsistent use of the base protected member 
    plate. The default constructor of Vehicle set plate to 0 pointer.
    However identify() function in Car and Truck pass plate to printf
    without checking for a null value. If the parameter for %s is a 
    null value, the behaviour of printf is not defined.

    The following code has an unwanted result:

        Truck t;
        t.identify();

    C++ Style
    Example 2
    Step 2


    The root of the problem is in the identify() member function 
    in the derived classes. They behave inconsistently with respect 
    to the protected interface of their base class. The base class
    represents a missing license plate number with anempty string,
    but the derived identify() functions assume that the string is
    never empty.

    A derived class cannot be coded before its base class. A derived
    class should conform consistently to the conventions established
    by its base class. In our example, the derived classes do not
    account for all of the legitimate states of the base part of their
    objects.

    To correct the bug, Car::identify() and Truck::identify() should
    test for empty string and take a reasonable action to handle that 
    case.

    An other important point to see is, that Vehicle has a non-virtual
    destructor. We know, that for a polymorphic type a virtual destructor
    is very important. However, if the derived classes have no destructor
    defined, the non-virtual base destructor causes no problem.As long as
    the derived classes do not need destructors, the base class may remain
    as it is.
 */

#include <iostream>
#include <string>
#include <vector>

class Vehicle
{
public:
    Vehicle() { }
    Vehicle(std::string p) : plate_(p) { }
    virtual ~Vehicle() { }
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
	std::cout << "Car, plate = " 
		  << (plate_.size() > 0 ? plate_ : "none") << "\n"; 
    }
};

class Truck : public Vehicle
{
public:
    Truck() : Vehicle() { }
    Truck(std::string p) : Vehicle(p) { };
    virtual void identify() const override { 
	std::cout << "Truck, plate = "
  		  << (plate_.size() > 0 ? plate_ : "none") << "\n";
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
Truck t4();  // most vexing parse 


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

 */
