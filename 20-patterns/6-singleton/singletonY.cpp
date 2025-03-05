#include "singletonY.h"

SingletonY *SingletonY::pinstance_ = nullptr;

SingletonY *SingletonY::get()
{
  if ( nullptr == pinstance_ )
  {
    pinstance_ = new SingletonY{};	  
  }
  return pinstance_;
}

