#ifndef A_H
#define A_H

struct X 
{
  int *ptr_ = new int{42};
  ~X() { delete ptr_; }  
};

#endif // A_H
