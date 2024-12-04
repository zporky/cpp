#ifndef PRIOQUE_H
#define PRIOQUE_H

#include <vector>

template <typename T, typename Cont, typename Comp>
class PrioQue
{
public:
       PrioQue(Comp comp) : comp_(comp) {}	
  int  size()  const { return heap_.size();   }
  bool empty() const { return 0 == size(); } 

  void push(int x); // insert to heap  	
  void pop();       // drop the top element
  const int &top() const { return heap_.front(); }
private:
  Cont heap_;	
  Comp comp_;
};

template <typename T, typename Cont, typename Comp>
void PrioQue<T,Cont,Comp>::push(int x)
{
  heap_.push_back(x);  // insert to the last place
  int pos = heap_.size() - 1; 
  int parent;
   
  while (pos && comp_(heap_[parent = (pos - 1) / 2] , heap_[pos]) ) 
  {
    std::swap(heap_[pos], heap_[parent]);
    pos = parent;
  }	
}

template <typename T, typename Cont, typename Comp>
void PrioQue<T,Cont,Comp>::pop()
{
  int last = heap_.back(); // move up
  heap_.pop_back();

  if (!heap_.empty()) 
  {
     const int size = heap_.size();
     int pos = 0, child;
     while ((child = 2 * pos + 1) < size) 
     {
       if (child + 1 < size && comp_(heap_[child], heap_[child+1]))
         child++;
       if (comp_(heap_[child], last)) // ==
         break;
       heap_[pos] = heap_[child];
       pos = child;
     }
     heap_[pos] = last;
  }
}

#endif // PRIOQUE

