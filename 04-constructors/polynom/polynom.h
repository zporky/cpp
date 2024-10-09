#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>
#include <string>

//
// invariant: the highest element >0
//

class Polynom
{
public:	
  Polynom( std::vector<int> v = {} );

  size_t deg() const { return _coeffs.size() > 0 ? _coeffs.size()-1 : 0; }
  
  int coeff(size_t i) const;
  int operator[](size_t i)  { return coeff(i); }

  int eval(int t) const;
  int operator()(int t) const { return eval(t); };

  std::string to_string() const;
private:
  std::vector<int>   _coeffs;

  std::string coeff_to_string(size_t i) const;
  void normalize();
};

#endif // POLYNOM_H
