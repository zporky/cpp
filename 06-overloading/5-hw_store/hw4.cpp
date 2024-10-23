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
//  step 4
//

/*
    The Role of a class 

    Motto: a public derived class should be 
           a specialization of its base class

    In one respect, the program has lost ground in the transformation.
    The original program specified only once, in Card::rebate(), that 
    the default rebate for cards i s45. With the current definition of 
    Component, the values of all non-zero rebates must be specified in 
    the object declarations. The program has no place to record a default
    rebate specifically for cards. The program does need to distinguish 
    cards from monitors. Inheritance can provide appropriate specialization
    with distinct constructors for cards and monitors.

    We must reintroduce the classes Card and Monitor to provide constructors
    with the appropriate rebate defaults.

    The specialization in the derived classes is limited to their 
    constructors. The default rebates are specified as default argument
    values to the constructors for Card and Monitor.

 */
 

#include <iostream>
#include <string>

using namespace std;

/*
enum CARD       {CDROM, TAPE, NETWORK };
enum MONITOR    { MONO, COLOR };
*/

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


class Card : public Component
{
public:
    Card( int p, std::string n, int r = 45) : Component( p, n, r)  { }
};

class Monitor : public Component
{
public:
    Monitor( int p,  std::string n, int r = 0) : Component( p, n, r)  { }
};

Card     Network(600, "Network", 45); // was: Component
Card     CDRom(1500, "CDRom", 135);   // was: Component
Card     Tape(1000, "Tape", 45);      // was: Component

Monitor  Color(1500, "Color");      // was: Component
Monitor  Monochrome(500, "Mono");   // was: Component


/*
  The reintroduction of Card and Monitor can simplify the program
  in other way. The arguments to Computer::Computer specify one CARD
  and one MONITOR value. The enumerations place a level of indirection
  between the constructor and the information it needs, without adding
  any flexibility. The constructor really needs the Component objects
  and has to map each enumeration value to an object. 

  Maintaining this mapping is complicated. To add another Monitor for
  example GreyScale, the programmer has to
    (1) add GREY_SCALE to the MONITOR enumeration type,
    (2) declare a GreyScale object, and
    (3) add a GREY_SCALE case to the constructor's switch statement.

  Card and Monitor are distinct types. If Computer::Computer takes
  pointers to objects as its arguments, the enumerations and the switch
  statements can be removed.
 
 */
class Computer
{
public:
    Computer( Card* c, Monitor *m ) : card_(c), mon_(m) { } // type safe!
    //      ~Computer();  Computere do not OWN the Components
    int     netPrice();
    void    print();
private:
    Card    *card_;  // was: Component
    Monitor *mon_;   // was: Component
};

int   Computer::netPrice()
{
    return mon_->netPrice() + card_->netPrice();
}

void    Computer::print()
{
    cout << "Configuration = " << card_->name() 
         << ", "               << mon_->name()  
         << ", net price = "   << netPrice() 
         << endl;
}

int main()
{
    Computer nm( &Network, &Monochrome );
    Computer cm( &CDRom,   &Monochrome );
    Computer tm( &Tape,    &Monochrome );
    Computer nc( &Network, &Color );
    Computer cc( &CDRom,   &Color );
    Computer tc( &Tape,    &Color );

    nm.print();
    cm.print();
    tm.print();
    nc.print();
    cc.print();
    tc.print();

    return 0;
}


