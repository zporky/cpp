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
//  step 1
//

/*
 
    A hardware store

    The program determines the price of various configurations of a 
    computer. Two selections must be made when configuring a computer:
    one for an expansion card and an other for monitor. The slot for 
    an expansion card must contain one of the three options:
      - CDROM drive
      - Tape drive
      - Netword card
    The monitor must be either:
      - Monochrom
      - Color

    Questions:
      - Are the classes providing the right abstractions?
      - Are there ways to eliminate complexity from the program by 
        changing its abstractions?

    In reading the program, think about how it may be simplified.
    Write your own version, compile, and run it. 
    What you gain and what you loose with the new version?

 */
 

#include <iostream>
#include <string>

using namespace std;

enum CARD       {CDROM, TAPE, NETWORK };
enum MONITOR    { MONO, COLOR };

class Card
{
public:
    virtual int         price() = 0;
    virtual std::string name() = 0;
    virtual int         rebate();
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

class Monitor
{
public:
    virtual int          price() = 0;
    virtual std::string  name() = 0;
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

int   Computer::netPrice()
{
    return mon->price() + card->price() - card->rebate();
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


