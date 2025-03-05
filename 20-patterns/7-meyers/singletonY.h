#ifndef SINGLETON_Y_H
#define SINGLETON_Y_H

#include "singletonX.h"

class SingletonY
{
public:	
  ~SingletonY() { delete ptr_; }	
  int getInt() const { return *ptr_; }
private:
  int *ptr_ = new int{SingletonX_get().getInt()};
};

SingletonY &SingletonY_get();

#endif  // SINGLETON_Y_H
