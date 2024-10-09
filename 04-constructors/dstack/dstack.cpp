
#include <stdexcept>
#include <iostream>
#include "dstack.h"

int DStack::size() const
{
  return _dvec.size();
}

bool DStack::empty() const
{
  return 0 == _dvec.size();
}

void DStack::push(double d)
{
  _dvec.push_back(d);
}

void DStack::pop()
{
  if ( 0 == _dvec.size() )
    throw std::out_of_range("stack empty");  // instead of "vector empty"
 
  _dvec.pop_back();
}

double DStack::top() const
{
  if ( 0 == _dvec.size() )
    throw std::out_of_range("stack empty");
 
  return _dvec[_dvec.size()-1];
}

double& DStack::top()
{
  if ( 0 == _dvec.size() )
    throw std::out_of_range("stack empty");
 
  return _dvec[_dvec.size()-1];
}

void print(std::ostream& os, const DStack& ds)
{
  os << "[ ";
  for (int i = 0; i < ds._dvec.size(); ++i)
    os << ds._dvec[i] << " ";
  os << "]" << std::endl;
}

