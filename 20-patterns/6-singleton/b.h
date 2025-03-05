#ifndef B_H
#define B_H

#include "a.h"
extern X x;

struct Y 
{
  int *ptr_ = new int{*x.ptr_};
  ~Y() { delete ptr_; }  
};

#endif // B_H
