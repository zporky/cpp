#include <iostream>
#include <list>
#include <string>
#include "x.h"

struct Ximpl
{
  void add( const char *s)  { lst_.push_back(s); }
  void print() const
  {
    for( auto s: lst_ ) std::cout << s << ' ';	  
  }
  std::list<std::string> lst_; 
};

X::X(const char *s) { new (impl_) Ximpl{}; reinterpret_cast<Ximpl*>(impl_)->add(s); }
X::X(const X& rhs)  { new(impl_) Ximpl{*reinterpret_cast<const Ximpl*>(rhs.impl_)}; }
X::~X() { reinterpret_cast<Ximpl*>(impl_)->~Ximpl(); }
X& X::operator=(const X& rhs) 
{ 
  if ( this != &rhs )
  {
    this->~X();
    *reinterpret_cast<Ximpl*>(impl_) = *reinterpret_cast<const Ximpl*>(rhs.impl_);
  }
  return *this;
}

void X::add(const char *s) { reinterpret_cast<Ximpl*>(impl_)->add(s);  }
void X::print() const      { reinterpret_cast<const Ximpl*>(impl_)->print(); }
