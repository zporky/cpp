#include "singletonX.h"

SingletonX *SingletonX::pinstance_ = nullptr;

SingletonX *SingletonX::get()
{
  if ( nullptr == pinstance_ )
  {
    pinstance_ = new SingletonX{};	  
  }
  return pinstance_;
}

