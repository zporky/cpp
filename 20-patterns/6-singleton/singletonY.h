#ifndef SINGLETON_Y_H
#define SINGLETON_Y_H

#include "singletonX.h"

class SingletonY
{
public:	
  static SingletonY *get();	
  ~SingletonY() { delete ptr_; }	
  int getInt() const { return *ptr_; }
private:
  static SingletonY *pinstance_;
  int *ptr_ = new int{SingletonX::get()->getInt()};
};

#endif  // SINGLETON_Y_H
