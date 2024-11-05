#include <iostream>

class Vec
{
public:
  void push_back(int i);
  int  size() const { return size_; }; 
  int  pop()  { return  buffer_[--size_]; };
private:
  void grow();

  int  capacity_ = 4;
  int  size_     = 0;   
  int *buffer_   = new int[capacity_];
};

void Vec::push_back(int i)
{
  if ( capacity_ == size_ )
  {
    grow();    
  }	  
  buffer_[size_++] = i;
}

void Vec::grow()
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

int main()
{
  Vec  v;
  int  inp;
  
  // read bufsize elements
  while ( std::cin >> inp )
  {
    v.push_back(inp);	  
  }
 
  // print elements in reverse order 
  for ( int i = v.size()-1; i >= 0; --i)
  {
    std::cout << v.pop() << (i==0?"\n":", "); 
  }
  return 0;
}


