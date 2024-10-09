#include <vector>
#include <string>
#include "polynom.h"

Polynom::Polynom( std::vector<int> v) : _coeffs( std::move(v) )
{
  normalize();	
}

void Polynom::normalize() 
{
  for (auto i = _coeffs.size(); i > 0 && 0 == _coeffs[i-1]; --i ) 	
  {
    _coeffs.pop_back();	  
  }	  
}

int Polynom::coeff(size_t i) const 
{ 
  return _coeffs.empty() || i>deg() ? 0 : _coeffs[i]; 
}

std::string Polynom::to_string() const 
{
  if ( _coeffs.empty() )
  {
    return "0";	  
  }	  
  std::string s;	
  for (size_t i = _coeffs.size(); i > 0; --i)
  {
    s += coeff_to_string(i-1);    
  }	  
  return s;
}

std::string Polynom::coeff_to_string(size_t i) const 
{
  std::string s;
  int coeff = _coeffs[i];

  if ( 0 == coeff )
    return s;
  if ( coeff < 0 )
    ; // nothing to do: std::to_string(coeff) prints - sign
  else if ( i < deg() )   
    s += "+";	  

  s += std::to_string(coeff);

  if( i > 0 )
  {
    s += "X^";
    s += std::to_string(i);    
  }	  
  return s; 
}

int Polynom::eval(int t) const
{
  int res = 0 ;	
  if ( ! _coeffs.empty() )
  {	  	  
    for ( size_t i = _coeffs.size()-1; i > 0; --i)
    {
      res += _coeffs[i];
      res *= t;    
    }  
    res += _coeffs[0];
  }  
  return res;
}	

