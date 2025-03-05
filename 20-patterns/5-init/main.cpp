#include <iostream>
#include "a.h"
#include "b.h"

extern X x;
extern Y y;

int main()
{
  std::cout << *x.ptr_ << ' ' << *y.ptr_ << '\n';	
}
