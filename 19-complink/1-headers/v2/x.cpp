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

X::X(const char *s) { pimpl_ = new Ximpl{}; pimpl_->add(s); }
X::X(const X& rhs)  { pimpl_ = new Ximpl{*rhs.pimpl_}; }
X::~X() { delete pimpl_; }
X& X::operator=(const X& rhs) 
{ 
  if ( this != &rhs )
  {
    delete [] pimpl_;
    pimpl_ = new Ximpl();
    *pimpl_ = *rhs.pimpl_;
  }
  return *this;
}

void X::add(const char *s) { pimpl_->add(s);  }
void X::print() const      { pimpl_->print(); }
