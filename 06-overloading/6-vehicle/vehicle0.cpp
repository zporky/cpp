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

#include <stdio.h>
#include <string.h>

class Vehicle
{
public:
    Vehicle() { plate = 0; }
    Vehicle(char *p)
    {
        plate = new char[strlen(p)+1];
        strcpy(plate, p);
    }
   ~Vehicle() { delete [] plate; }
    virtual void identify()     { printf("generic vehicle\n"); }

protected:
    char   *plate;
};

class Car : public Vehicle
{
public:
    Car() : Vehicle() { }
    Car(char *p) : Vehicle(p) { };
    void identify() { printf("car with plate %s\n", plate); }
};

class Truck : public Vehicle
{
public:
    Truck() : Vehicle() { }
    Truck(char *p) : Vehicle(p) { };
    void identify() { printf("truck with plate %s\n", plate); }
};

class Garage
{
public:
    Garage(int max);
   ~Garage();

    int       accept(Vehicle*);
    Vehicle  *release(int bay);
    void      listVehicles();
private:
    int       maxVehicles;
    Vehicle **parked;
};

Garage::Garage(int max)
{
    maxVehicles = max;
    parked = new Vehicle*[maxVehicles];
    for( int bay = 0; bay < maxVehicles; ++bay ) 
    {
        parked[bay] = 0;
    }
}

Garage::~Garage()
{
    delete [] parked;
}

int Garage::accept(Vehicle *veh)
{
    for( int bay = 0; bay < maxVehicles; ++bay )
        if( !parked[bay] )
        {
            parked[bay] = veh;
            return( bay );
        }
    return( -1 );       // No free bay
}

Vehicle *Garage::release(int bay)
{
    if( bay < 0 || bay > maxVehicles )
        return 0;
    Vehicle *veh = parked[bay];
    parked[bay] = 0;
    return( veh );
}

void    Garage::listVehicles()
{
    for( int bay = 0; bay < maxVehicles; ++bay )
        if( parked[bay] )
        {
            printf("Vehicle in bay %d is: ", bay);
            parked[bay]->identify();
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
    Garage Park(14);

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

Vehicle in bay 0 is: car with plate AAA100
Vehicle in bay 2 is: car with plate CCC300
Vehicle in bay 3 is: truck with plate SSS888

 */
