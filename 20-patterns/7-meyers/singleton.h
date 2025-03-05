#ifndef SINGLETON_X_H
#define SINGLETON_X_H

class SingletonX
{
public:	
  ~SingletonX() { delete ptr_; }	
  int getInt() const { return *ptr_; }
private:
  static T *pinstance_;
  int      *ptr_ = new int{42};
};

template <typename 
SingletonX *SingletonX::pinstance_ = nullptr;

SingletonX *SingletonX::get()
{
  if ( nullptr == pinstance_ )
  {
    pinstance = new SingletonX{};	  
  }
  return pinstance;
}

#endif  // SINGLETON_X_H
