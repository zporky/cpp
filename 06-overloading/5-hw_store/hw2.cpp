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
//  step 2
//

/*
 
   Finding a Common Abstraction

    Motto: Concentrate common abstractions in a base class.

    The class interfaces of Card and Monitor are similar: Both have 
    price() and name() as pure virtual functions. The difference is 
    that class Card has an additional virtual function: rebate().
    Studying the similarities and differences between these classes
    will clarify their relationships and lead to a better program.

    Card and Monitor are similar, but they are not formally related 
    in the inheritance hierarchy. Both Card and Monitor have price()
    and name() memberfunctions. They are both computer components. 
    It makes more sense to formalize that common abstraction in a 
    further base class called: Component. This makes the semantic 
    of a computer explicitelly defined with the help of C++ language
    tools.
 */
 

#include <iostream>
#include <string>

using namespace std;

enum CARD       {CDROM, TAPE, NETWORK };
enum MONITOR    { MONO, COLOR };

class Component
{
public:
    virtual ~Component() { }    
    virtual int         price() = 0;
    virtual std::string name() = 0;
    virtual int         rebate() { return 0; };  //default rebate
            int         netPrice();
};

class Card : public Component
{
public:
    virtual int         price() = 0;
    virtual std::string name() = 0;
    virtual int         rebate();
};

class Monitor : public Component
{
public:
    virtual int         price() = 0;
    virtual std::string name() = 0;
    // no rebate
};

class Network : public Card
{
public:
    int          price();
    std::string  name();
};

class Tape : public Card
{
public:
    int          price();
    std::string  name();
};

class CDRom : public Card
{
public:
    int         price();
    std::string name();
    int         rebate();
};

class Color : public Monitor
{
public:
    int          price();
    std::string  name();
};

class Monochrome : public Monitor
{
public:
    int          price();
    std::string  name();
};

int   Card::rebate()  { return 45; }

int         Network::price()    { return 600; }
std::string Network::name()     { return "Network"; }

int         CDRom::price()      { return 1500; }
std::string CDRom::name()       { return "CDRom"; }
int         CDRom::rebate()     { return 135; }

int         Tape::price()       { return 1000; }
std::string Tape::name()        { return "Tape"; }

int         Color::price()      { return 1500; }
std::string Color::name()       { return "Color"; }

int         Monochrome::price() { return 500; }
std::string Monochrome::name()  { return "Mono"; }

class Computer
{
public:
            Computer( CARD, MONITOR );
           ~Computer();
    int     netPrice();
    void    print();
private:
    Card    *card;
    Monitor *mon;
};

Computer::Computer( CARD c, MONITOR m )
{
    switch( c )
    {
        case NETWORK:   card = new Network;     break;
        case CDROM:     card = new CDRom;       break;
        case TAPE:      card = new Tape;        break;
    }
    switch( m )
    {
        case MONO:      mon = new Monochrome;   break;
        case COLOR:     mon = new Color;        break;
    }
}

Computer::~Computer()
{
    delete card;
    delete mon;
}


/*
    Unification of the base abstractions (creating the common base
    class Component permits a simplification of the pricing. Both
    Card and Monitor have a rebate, so we can implement netPrice()
    in Component:

 */

int   Component::netPrice()
{
    return price() - rebate();
}

/*
    As a consequece we can drastically simplify the netPrice() of 
    Computer. It is the sum of netPrice()-es of the Components.
    
 */
int   Computer::netPrice()
{
    //  was: return mon->price() + card->price() - card->rebate();
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


