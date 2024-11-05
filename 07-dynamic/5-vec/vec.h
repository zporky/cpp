#ifndef VEC_H
#define VEC_H

#include <iostream>

class Vec
{
public:
   Vec() {}
   Vec(const Vec &rhs);
   Vec(Vec &&rhs);
   Vec& operator=(const Vec &rhs);
   Vec& operator=(Vec &&rhs);		   
  ~Vec();	
  
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
  void copy(const Vec &rhs);
  void move(Vec &&rhs);
  void release();

  int  capacity_ = 0;
  int  size_     = 0;   
  int *buffer_   = nullptr;
};

#endif // VEC_H
