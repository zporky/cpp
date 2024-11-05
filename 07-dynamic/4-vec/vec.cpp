#include <iostream>
#include "vec.h"

void Vec::push_back(int i)
{
  if ( capacity_ == size_ )
  {
    grow();    
  }	  
  buffer_[size_++] = i;
}

void Vec::pop_back()
{
  --size_;
}

void Vec::grow()
{
  int *ptr = new int[2*capacity_];
  capacity_ *= 2;
  for ( int i = 0; i < size_; ++i)
  {
    ptr[i] = buffer_[i];	      
  }
  delete [] buffer_;
  buffer_ = ptr;
}

