
#include <iostream>
#include <stdexcept>  // for std::out_of_range

#include "date.h"

/* anonymous namespace, visible only in this source */
namespace 
{
  const int day_in_month[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };
}

Date::Date( int y, int m, int d) : year_(y), month_(m), day_(d)
{
  checkDate( y, m, d);  // may throw std::out_of_range
}

void Date::setDate( int y, int m, int d)
{
  checkDate( y, m, d);  // may throw std::out_of_range

  year_  = y;
  month_ = m;
  day_   = d;
}

Date& Date::operator++()       // pre-fix increment
{
  next();  
  return *this;	
}
Date  Date::operator++(int)    // post-fix increment
{
  Date old{*this}; 
  next();
  return old;  
}
Date& Date::operator+=( int n) // add n days
{
  add(n);
  return *this;  
}	

void Date::checkDate( int y, int m, int d)
{
  // TODO: leap year
  if ( ( 0 == y ) ||                        
       ( m < 1 || m > 12 ) ||
       ( d < 1 || d > day_in_month[m-1] ) )
  {
    throw std::out_of_range{"Invalid date"};	  
  }
}

void Date::next()
{
  ++day_;
  /* TODO: leap year */
  if ( day_-1 == day_in_month[month_-1])
  {
    day_ = 1;
    ++month_;
  }
  if ( 13 == month_ )
  {
    month_ = 1;
    if ( 0 == ++year_ ) ++year_;
  } 
}

void Date::add(int n)
{
  for (int i = 0; i < n; ++i)
    next();  // optimize later if necessary
}

void Date::get( std::istream& is)
{
  int y, m, d;
  if ( is >> y >> m >> d ) // have to check for success
  {
    setDate( y, m, d);
  }
}

void Date::put( std::ostream& os) const
{
  // better to build on accessors;
  os << "[ " << getYear()  << "."
             << getMonth() << "."
             << getDay()   << " ]";
}

std::ostream& operator<<(std::ostream& os, Date d)
{
  d.put(os);	
  return os;
}

std::istream& operator>>(std::istream& is, Date& d)
{
  d.get(is);
  return is;  
}

