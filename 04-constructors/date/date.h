
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>  // for std::logic_error

/* 
 * simple date class 
 *
 * just an example for object-oriented programming
 * for real programs, use std::chrono from <chrono>
 *
 */

class date
{
public:
  /* exception to express bad date */
  class bad_date_t : public std::logic_error // inherited std::exception 
  { 
  public: 
    bad_date_t(const char *s) : std::logic_error(s) { }
  };
   
  /* constructors */
  date( int y, int m=1, int d=1) { setDate( y, m, d); }
  date( const char *s);   /* convert from char* */

  /* accessors */
  int  getYear()  const { return year; }
  int  getMonth() const { return month; }
  int  getDay()   const { return day; }

  /* setters */
  date&  setYear( int y)  { year  = y; return *this; }
  date&  setMonth( int m) { month = m; return *this; }
  date&  setDay( int d)   { day   = d; return *this; }

  void  setDate( int y, int m, int d);

  /* additive */    
  date&  next();
  date&  add( int n);
  /* prev(), ... */

  /* operators */
  date& operator++()       { return next(); }
  date  operator++(int)    { date curr(*this); next(); return curr; };
  date& operator+=( int n) { return add(n); }
  /* operator--(), ... */

  /* io */
  void get( std::istream& is);
  void put( std::ostream& os) const;

private:
  /* helpers */
  void checkDate( int y, int m, int d);

  /* data members */
  int year;
  int month;
  int day;
};

/* global operators */
bool operator<( date d1, date d2);

inline bool operator==( date d1, date d2) { return !(d1<d2 || d2<d1); }
inline bool operator!=( date d1, date d2) { return d1<d2 || d2<d1; }
inline bool operator<=( date d1, date d2) { return !(d2<d1); }
inline bool operator>=( date d1, date d2) { return !(d1<d2); }
inline bool operator>( date d1, date d2)  { return d2<d1; }

/* global io operators */
std::istream& operator>>( std::istream& is, date& d);
std::ostream& operator<<( std::ostream& os, const date &d);

#endif /* DATE_H */

