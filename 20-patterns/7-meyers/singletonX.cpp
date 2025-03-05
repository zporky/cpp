#include "singletonX.h"

SingletonX &SingletonX_get()
{
  static SingletonX instance_;	
  return instance_;
}

