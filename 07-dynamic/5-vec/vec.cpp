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

void Vec::copy(const Vec &rhs)
{
  capacity_ = rhs.capacity_;
  size_     = rhs.size_;  
  buffer_   = new int[capacity_];

  for ( int i = 0; i < size_; ++i)
  {
    buffer_[i] = rhs.buffer_[i];
  }  
}

void Vec::move(Vec &&rhs)
{
  capacity_ = rhs.capacity_;
  size_     = rhs.size_;  
  buffer_   = rhs.buffer_;

  rhs.capacity_ = 0;
  rhs.size_     = 0;
  rhs.buffer_   = nullptr;
}

void Vec::release()
{
  delete[] buffer_;	
}

void Vec::grow()
{
  if ( 0 == capacity_ )
  {
    capacity_ = 4; 	  
    buffer_ = new int[4];
  }
  else
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
}

Vec::Vec(const Vec &rhs)
{
  copy(rhs);
}

Vec::Vec(Vec &&rhs)
{
  move(std::move(rhs));	
}

Vec& Vec::operator=(const Vec &rhs)
{
  if ( this != &rhs )
  {
     release();
     copy(rhs);     
  }
  return *this;  
}

Vec& Vec::operator=(Vec &&rhs)
{
  if ( this != &rhs )
  {
     release();
     move(std::move(rhs));     
  }
  return *this;  
}


Vec::~Vec()
{
  release();	
}

