#ifndef REVERSE_H
#define REVERSE_H

#include <iostream>
#include <vector>

template <typename T>
void print(std::ostream& os, const std::vector<T> &v)
{
  for ( auto x : v )
  {
    os << x << ' ';	  
  }
  os << '\n';
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v)
{
  print(os, v);	
  return os;
}

template <typename T>
void reverse(std::vector<T> &v)
{
  int half = v.size()/2;
  for ( int i = 0; i < half; ++i)
  {
    std::swap(v[i], v[v.size()-1-i]);	  
  }  
}

#endif // REVERSE_H
