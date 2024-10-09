
/*
 *  calendar - list of dates + hours with associated events
 *
 *  implementation with std::map as days and
 *      inside a day: an other map for hours
 *  std::map is a key-value pair with no key duplication
 *  std::map is sorted: elements are ordered by the key
 *
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <iomanip>  // just for setw(): fine formatting in print
#include <map>
#include <string>
#include "date.h"  // we use the date we implemented earlier


class calendar
{
public:
  void print() const /* for debug */
  {
      for ( std::map<date,std::map<int,std::string> >::const_iterator i  
               = _entries.begin(); i != _entries.end(); ++i)
      {
          for ( std::map<int,std::string>::const_iterator j
                  = i->second.begin(); j != i->second.end(); ++j )
          {
              std::cout << i->first  << " "
                        << std::setw(2) << j->first << " : " 
                        << j->second << std::endl;
          }
      }
  }

  bool insert( int y, int m, int d, int h, std::string e)
  {
      date key1(y,m,d);
      // If date not exists or when exists and hour not exists 
      if ( _entries.count(key1) == 0 || _entries[key1].count(h) == 0 )
      {      
          _entries[key1][h] = e;
          return true;
      }
      return false;
  }

  bool replace( int y, int m, int d, int h, std::string e)
  {
      date key1(y,m,d);
      // Only both date and hour entry exist. We use that && is shortcut
      if ( _entries.count(key1) == 1 && _entries[key1].count(h) == 1 )
      {
          _entries[key1][h] = e;
          return true;
      }
      return false; 
  }

  std::string get(int y, int m, int d, int h) const
  {
      date key1(y,m,d);
      if ( _entries.count(key1) == 1 && 
           _entries.find(key1)->second.count(h) == 1)
          return _entries.find(key1)->second.find(h)->second;
      else
          return std::string();
  }

  int size() const 
  {
      int sz = 0;
      for ( std::map<date,std::map<int,std::string> >::const_iterator i  
               = _entries.begin(); i != _entries.end(); ++i)
      {
          sz += i->second.size();
      }
      return sz;
  }
private:
  std::map< date, std::map<int, std::string> >  _entries;
};


#endif /* CALENDAR_H */
