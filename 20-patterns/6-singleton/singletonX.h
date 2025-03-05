#ifndef SINGLETON_X_H
#define SINGLETON_X_H

class SingletonX
{
public:	
  static SingletonX *get();	
  ~SingletonX() { delete ptr_; }	
  int getInt() const { return *ptr_; }
private:
  static SingletonX *pinstance_;
  int      *ptr_ = new int{42};
};

#endif  // SINGLETON_X_H
