/*
 The practice of abstraction is central to the creation of software.
 The single most important abstraction mechanism in C++ is the class.
 A class captures the common properties of the objects instantiated 
 from it; a class characterizes the common behaviour of all objects 
 that are its instances. Identifying appropriate abstractions is a 
 critical part of programming in C++. To find good abstractions, the
 programmer must understand the underlying properties of the objects 
 manipulated by the program.

 To study the class as an abstraction mechanism, we examine a sample 
 program and evaluate its strength and weaknesses, particulary with
 respect to the choice of classes. ALternative ways of writing the 
 program with different classes and different class relationships 
 appear. General rules of programming style, which will improve other
 programs, then emerge from rethinking the design and rewriting the 
 code of the sample program.

 */


//
//  C++ style           
//  example 1
//  step 3
//

/*
 
    Differences between classes 

    Motto: a class should describe a set of objects

    We were encountered the similarities between the classes, it is
    time to answer the question: what makes these classes different?
    What is the difference between CDRom and Network? The difference 
    is found in the derived class declarations. Neither class adds
    new members; they have no additional state or supplementary 
    behaviour. The difference is in their definitions of the virtual
    functions price(), name() and rebate().

    These virtual functions do not vary the behaviour of the objects
    of the different derived classes. The only difference between a
    Network object and a CDRom object is the values returned by their
    virtual functions.

    In general, the behaviour of an object is the way it responds to 
    each stimulus it can receive. Viewing an object in terms of its 
    response to stimuli emphasizes the independence of objects - each 
    object is an autonomous component of a program in execution. 
    
    The most common form of stimulus is a member function call. The
    object responds by executing its member function, either to perform 
    a side effect or to return a value or both. Polymorphism - virtual
    functions in C++ - permits the objects of different types (classes)
    to respond in different ways to the same stimulus. In this program,
    the virtual functions do not produce variation in behaviour between 
    objects.
    
    The difference between the derived classes can be seen from another 
    perspective. All information in an object of one of these leaf classes
    is incorporated in its type. A Tape object, for example has no data 
    members, every Tape object is equivalent to every other. There is
    no reason to instantiate more than one Tape object, because they 
    must all behave in the very same way. Such a type is called Singleton,
    and sometimes is an essential part of a program. But a program 
    containing only singletons - that is very suspicious.

    Generality is an essential property of a program. Code fragments 
    addressed to solve general problems are more usefull than those that
    are restricted to specific problems. In practice, a program cannot 
    afford to define a different class for every object that it creates. 
    Rather, each class should characterize a set of objects.
 */
 

#include <iostream>
#include <string>

using namespace std;

enum CARD       {CDROM, TAPE, NETWORK };
enum MONITOR    { MONO, COLOR };

class Component
{
public:
    Component(int p, std::string n, int r = 0) :
	    price_(p), name_(n), rebate_(r) { }

    int         price()  const   { return price_; }
    std::string name()   const   { return name_;  }
    int         rebate() const   { return rebate_; } 
    int         netPrice() const { return price() - rebate(); }
private:
    int         price_;
    std::string name_;    
    int         rebate_;
};

/*
   The 1st version of the program was drawn into the common trap of
   thinking that inheritance and virtual functions are the only ways
   to program in C++. The excessive use of inheritance resulted in 
   class declarations in which some classes are so specialized that 
   each describes just one object. Inheritance and polymorphism are
   powerful tools when behavious varies between objects of different 
   classes. However, in this program the variation is in values, not 
   behaviour.
   
   Simple data members and non-virtual functions are sufficient to 
   represent the differences between componenct objects.

   The difference between components is now a difference in value,
   not a difference in type. The different values are established by
   arguments to the constructor.

   Use data members for variation in value, reserve virtual functions
   for variation in behaviour.

 */

Component Network(600, "Network", 45);
Component CDRom(1500, "CDRom", 135);
Component Tape(1000, "Tape", 45);
Component Color(1500, "Color");
Component Monochrome(500, "Mono");

/*
   The objects above are automatic ones, in a real program perhaps 
   we create them on user request from the heap.
   
 */

class Computer
{
public:
            Computer( CARD, MONITOR );
    //      ~Computer();  Computere do not OWN the Components
    int     netPrice();
    void    print();
private:
    Component *card;  // was: Card
    Component *mon;   // was: Monitor
};

Computer::Computer( CARD c, MONITOR m )
{
    switch( c )
    {
        case NETWORK:   card = &Network;     break;
        case CDROM:     card = &CDRom;       break;
        case TAPE:      card = &Tape;        break;
    }
    switch( m )
    {
        case MONO:      mon = &Monochrome;   break;
        case COLOR:     mon = &Color;        break;
    }
}

/* No need for destructor 
Computer::~Computer()
{
    delete card;
    delete mon;
}
*/

int   Computer::netPrice()
{
    return mon->netPrice() + card->netPrice();
}

void    Computer::print()
{
    cout << "Configuration = " << card->name() 
         << ", "               << mon->name()  
         << ", net price = "   << netPrice() 
         << endl;
}

int main()
{
    Computer nm( NETWORK, MONO );
    Computer cm( CDROM,   MONO );
    Computer tm( TAPE,    MONO );
    Computer nc( NETWORK, COLOR );
    Computer cc( CDROM,   COLOR );
    Computer tc( TAPE,    COLOR );

    nm.print();
    cm.print();
    tm.print();
    nc.print();
    cc.print();
    tc.print();

    return 0;
}


