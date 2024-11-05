#ifndef VEC_H
#define VEC_H

#include <iostream>

class Vec
{
public:
  void push_back(int i);
  void pop_back();

  int  size() const { return size_; }; 
  bool empty() const { return 0 == size(); }

  int  &front() { return buffer_[0]; }
  int  &back()  { return buffer_[size_-1]; }
  
  int       &operator[](int idx)       { return buffer_[idx]; }
  const int &operator[](int idx) const { return buffer_[idx]; }
private:
  void grow();

  int  capacity_ = 4;
  int  size_     = 0;   
  int *buffer_   = new int[capacity_];
};

#endif // VEC_H
