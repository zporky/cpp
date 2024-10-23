#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
public:
  Date( int y, int m=1, int d=1);  // constructor 

  // getters
  int   getYear()  const { return year_;  }  
  int   getMonth() const { return month_; }  
  int   getDay()   const { return day_;   }  
  void  setDate( int y, int m, int d);   // set a date

  Date& operator++();       // pre-fix increment
  Date  operator++(int);    // post-fix increment
  Date& operator+=( int n); // add n days
			   
  void get( std::istream& is);       // read from a stream
  void put( std::ostream& os) const; // write to a stream
				     
private:
  void checkDate( int y, int m, int d);  // check consistency
					 // 
  void next();     // set the next day 
  void add(int n); // add n days 

  int year_ ;
  int month_;
  int day_  ;
};

std::ostream& operator<<(std::ostream& os, Date d);
std::istream& operator>>(std::istream& is, Date& d);

inline bool operator<(const Date &d1, const Date &d2)
{  
  return (d1.getYear() <  d2.getYear())
      || (d1.getYear() == d2.getYear() 
                  && d1.getMonth() <  d2.getMonth())
      || (d1.getYear() == d2.getYear() 
                  && d1.getMonth() == d2.getMonth()
                  && d1.getDay()   <  d2.getDay());
}
inline bool operator>( Date d1, Date d2)  
{ 
  return d2 < d1; 
}
inline bool operator<=( Date d1, Date d2) 
{ 
  return !(d2 < d1); 
}
inline bool operator>=( Date d1, Date d2) 
{ 
  return !(d1 < d2); 
}
inline bool operator!=( Date d1, Date d2) 
{ 
  return  d1 < d2 || d2 < d1; 
}
inline bool operator==( Date d1, Date d2) 
{ 
  return  ! ( d1 == d2 ); 
}

#endif  // DATE_H
