#include "singletonY.h"

SingletonY &SingletonY_get()
{
  static SingletonY instance_;	  
  return instance_;
}

