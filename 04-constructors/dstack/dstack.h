
#ifndef DSTACK_H
#define DSTACK_H

#include <iosfwd>     // only declarations of <iostream>
#include "dvector.h"

class DStack
{
  friend void print(std::ostream&, const DStack&); // give access rights 
               
public:
  // no need for special member functions, 
  // DVector works as it is

  int     size() const;    // actual size 
  bool    empty() const;   // size() == 0

  double  top() const;	   // read top element
  double& top();	   // access top element

  void    push(double d);  // append to end
  void    pop();	   // remove from end;

private:
  DVector _dvec;   // reuse DVector
};

void print(std::ostream& os, const DStack& ds);	// print DStack for debug

#endif /* DSTACK_H */
