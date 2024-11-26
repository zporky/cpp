#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack
{
public:
  int size() const   { return v_.size();   }
  bool empty() const { return 0 == size(); }
 	
  void push(int x)  { v_.push_back(x);  }   // push_back
  void pop()        { v_.pop_back();    }   // pop_back
  int &top()       { return v_.back(); }
  const int &back()  const { return v_.back(); }
private:	
  std::vector<int> v_;
};

#endif // STACK_H
