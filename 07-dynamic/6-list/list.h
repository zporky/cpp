#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
public:
   List() {}
   List(const List &rhs);
   List(List &&rhs);
   List& operator=(const List &rhs);
   List& operator=(List &&rhs);		   
  ~List();	
  
  void push_back(int i);
  void pop_back();

  int  size() const { return size_; }; 
  bool empty() const { return 0 == size(); }

  int  &front() { return first_->val_; }
  int  &back()  { return last_->val_; }
  
private:
  struct Elem
  {
    Elem(int v) : val_(v) { } 	  
    Elem *prev_ = nullptr;
    Elem *next_ = nullptr;    
    int   val_;
  };

  void copy(const List &rhs);
  void move(List &&rhs);
  void release();

  int   size_  = 0;   
  Elem *first_ = nullptr;
  Elem *last_  = nullptr;
};

#endif // LIST_H
