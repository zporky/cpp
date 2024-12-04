#ifndef VEC_H
#define VEC_H

#include <iostream>

template <typename T>
class Vec
{
public:
   Vec() {}
   Vec(const Vec &rhs);
   Vec(Vec &&rhs);
   Vec& operator=(const Vec &rhs);
   Vec& operator=(Vec &&rhs);		   
  ~Vec();	
  
  void push_back(const T &i);
  void pop_back();

  int  size() const { return size_; }; 
  bool empty() const { return 0 == size(); }

  T  &front() { return buffer_[0]; }
  T  &back()  { return buffer_[size_-1]; }
  
  const T &front() const { return buffer_[0]; }
  const T &back()  const { return buffer_[size_-1]; }
  
  T       &operator[](int idx)       { return buffer_[idx]; }
  const T &operator[](int idx) const { return buffer_[idx]; }
private:
  void grow();
  void copy(const Vec &rhs);
  void move(Vec &&rhs);
  void release();

  int  capacity_ = 0;
  int  size_     = 0;   
  T   *buffer_   = nullptr;
};

template <typename T>
void Vec<T>::push_back(const T& i)
{
  if ( capacity_ == size_ )
  {
    grow();    
  }	  
  buffer_[size_++] = i;
}

template <typename T>
void Vec<T>::pop_back()
{
  --size_;
}

template <typename T>
void Vec<T>::copy(const Vec &rhs)
{
  capacity_ = rhs.capacity_;
  size_     = rhs.size_;  
  buffer_   = new T[capacity_];

  for ( int i = 0; i < size_; ++i)
  {
    buffer_[i] = rhs.buffer_[i];
  }  
}

template <typename T>
void Vec<T>::move(Vec &&rhs)
{
  capacity_ = rhs.capacity_;
  size_     = rhs.size_;  
  buffer_   = rhs.buffer_;

  rhs.capacity_ = 0;
  rhs.size_     = 0;
  rhs.buffer_   = nullptr;
}

template <typename T>
void Vec<T>::release()
{
  delete[] buffer_;	
}

template <typename T>
void Vec<T>::grow()
{
  if ( 0 == capacity_ )
  {
    capacity_ = 4; 	  
    buffer_ = new T[4];
  }
  else
  {
    T *ptr = new T[2*capacity_];
    capacity_ *= 2;
    for ( int i = 0; i < size_; ++i)
    {
      ptr[i] = buffer_[i];	      
    }
    delete [] buffer_;
    buffer_ = ptr;
  }
}

template <typename T>
Vec<T>::Vec(const Vec &rhs)
{
  copy(rhs);
}

template <typename T>
Vec<T>::Vec(Vec &&rhs)
{
  move(std::move(rhs));	
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
  if ( this != &rhs )
  {
     release();
     copy(rhs);     
  }
  return *this;  
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs)
{
  if ( this != &rhs )
  {
     release();
     move(std::move(rhs));     
  }
  return *this;  
}


template <typename T>
Vec<T>::~Vec()
{
  release();	
}

#endif // VEC_H
