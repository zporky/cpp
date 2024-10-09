
#include <stdexcept>
#include "dvector.h"


DVector::DVector()
{
  _capacity = 4;
  _size = 0;
  _ptr = new double[_capacity];
}

DVector::DVector(const DVector& rhs)
{
  copy(rhs);
}

DVector& DVector::operator=(const DVector& rhs)
{
  if ( this != &rhs )  // avoid x = x
  {
    release();
    copy(rhs);
  }
  return *this;  // for x = y = z
}

DVector::~DVector()
{
  release();
}

void DVector::copy(const DVector& rhs)
{
  _capacity = rhs._capacity;
  _size = rhs._size;
  _ptr = new double[_capacity];

  for (int i = 0; i < _size; ++i)
    _ptr[i] = rhs._ptr[i];
}

void DVector::release()
{  
  delete [] _ptr;
}


void DVector::grow()
{
  double *_oldptr = _ptr;
  _capacity = 2 * _capacity;
  _ptr = new double[_capacity];

  for ( int i = 0; i < _size; ++i)
    _ptr[i] = _oldptr[i];

  delete [] _oldptr;
}

int DVector::size() const
{
  return _size;
}

double& DVector::at(int i)
{
  if ( i >= _size )
    throw std::out_of_range("bad index");

  return _ptr[i];
} 

double DVector::at(int i) const
{
  if ( i >= _size )
    throw std::out_of_range("bad index");

  return _ptr[i];
} 

double& DVector::operator[](int i)
{
  return _ptr[i];
}

double DVector::operator[](int i) const
{
  return _ptr[i];
}

void DVector::push_back(double d)
{
  if ( _size == _capacity )
    grow();

  _ptr[_size] = d;
  ++_size;  
}


void DVector::pop_back()
{
  if ( 0 == _size )
    throw std::out_of_range("vector empty");
 
  --_size;
}

