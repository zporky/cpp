#include <vector>
#include <iostream>

template <typename T>
struct X
{
  T* begin() { return &v_[0]; }
  T* end()   { return &v_[v_.size()]; }
  void push_back(T t) { v_.push_back(t); }

  std::vector<T> v_;
};

int main()
{
  X<int> x;
    
  x.push_back(1);
  x.push_back(2);
  x.push_back(3);
  x.push_back(4);

  for ( auto i : x )
  {
    std::cout << i << '\n';	  
  }
}
