#ifndef QUEUE_H
#define QUEUE_H

#include <deque>

class Queue
{
public:
  int size() const   { return v_.size();   }
  bool empty() const { return 0 == size(); }
 	
  void push(int x)  { v_.push_back(x);  }
  void pop()        { v_.pop_front();    }
  int &back()       { return v_.back(); }
  int &front()      { return v_.front(); }
  const int &back()  const { return v_.back(); }
  const int &front() const { return v_.front(); }
private:	
  std::deque<int> v_;
};

#endif // QUEUE_H
