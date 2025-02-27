#include <iostream>
#include <list>
#include <string>

class X
{
public:
  X( const char *s) { lst_.push_back(s); }
  void add( const char *s)  { lst_.push_back(s); }
  void print() const
  {
    for( auto s: lst_ ) std::cout << s << ' ';	  
  }
private:
  std::list<std::string> lst_; 
};
