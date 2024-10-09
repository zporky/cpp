
#include <iostream>
#include <cstring>
#include <cstdlib>

#include "date.h"

using namespace std;

namespace /* anonym namespace, visible only in this source */
{
  const int day_in_month[] =
       { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

/* constructor */
date::date( const char *s)
{
  /* strchr and strrchr from <cstring> */
  const char *p1 = strchr( s, '.');
  const char *p2 = strrchr( s, '.');

  if ( p1 && p2 && p1 != p2 )
  {
    /* atoi from <cstdlib> */
    int y = atoi(s);
    int m = atoi(p1+1);
    int d = atoi(p2+1);

    setDate( y, m, d);
  }
  else
  {
    throw bad_date_t("Wrong string");
  }
}

void date::setDate( int y, int m, int d)
{
  checkDate( y, m, d);

  year  = y;
  month = m;
  day   = d;
}

/* additive */
date& date::next()
{
  ++day;

  /* TODO: leap year */
  if ( day-1 == day_in_month[month-1])
  {
    day = 1;
    ++month;
  }
  if ( 13 == month )
  {
    month = 1;
    ++year;
  } 
  return *this; // return reference to *this object 
}

date& date::add( int n)
{
  for (int i = 0; i < n; ++i)
  {
    next(); /* KISS */
  }
  return *this; // return reference to *this object 
}

/* input-output */
void date::get( std::istream& is)
{
  int y, m, d;
  if ( is >> y >> m >> d ) // have to check for success
  {
    setDate( y, m, d);
  }
}

void date::put( std::ostream& os) const
{
  // better to build on accessors;
  os << "[ " << getYear()  << "." 
             << getMonth() << "." 
             << getDay()   << " ]";
}

/* helpers */
void date::checkDate( int y, int m, int d)
{
  if ( 0 == y )  		throw bad_date_t("Bad year");
  if ( m < 1 || m > 12 )	throw bad_date_t("Bad month");
  if ( d < 1 || d > day_in_month[m-1] )  throw bad_date_t("Bad day");
}


/* ==============================  Globals ========================= */


/* global operators */
bool operator<( date d1, date d2)
{
  return (d1.getYear() <  d2.getYear())  
      || (d1.getYear() == d2.getYear() && d1.getMonth() <  d2.getMonth())  
      || (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth()
                                      && d1.getDay()   <  d2.getDay());

}

/* io operators built top on get and set */
istream& operator>>( istream& is, date& d)
{
  d.get( is);
  return is;  /* important to chain reads */
}

ostream& operator<<( ostream& os, const date &d)
{
  d.put( os);
  return os;	/* important to chain writes */
}



