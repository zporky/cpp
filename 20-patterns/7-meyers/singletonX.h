#ifndef SINGLETON_X_H
#define SINGLETON_X_H

class SingletonX
{
public:	
  ~SingletonX() { delete ptr_; }	
  int getInt() const { return *ptr_; }
private:
  int      *ptr_ = new int{42};
};

SingletonX &SingletonX_get();

#endif  // SINGLETON_X_H
