#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
class List
{
   struct Elem;	
public:
   class Iterator
   {	   
   public:
     Iterator(Elem *p) : ptr_(p) { }
     
     T& operator*() { return ptr_->val_; }
     Iterator& operator++() { ptr_ = ptr_->next_; return *this; }
     Iterator  operator++(int) { 
	      Iterator it{*this}; ptr_ = ptr_->next_; return *this; }

     bool operator==(Iterator it) { return ptr_ == it.ptr_; }
     bool operator!=(Iterator it) { return ptr_ != it.ptr_; }
   private:  
     Elem *ptr_;
   };	   

   List() {}
   List(const List &rhs);
   List(List &&rhs);
   List& operator=(const List &rhs);
   List& operator=(List &&rhs);		   
  ~List();	
  
  void push_back(const T &i);
  void pop_back();

  int  size() const { return size_; }; 
  bool empty() const { return 0 == size(); }

  T  &front() { return first_->val_; }
  T  &back()  { return last_->val_; }
  const T  &front() const { return first_->val_; }
  const T  &back()  const { return last_->val_; }

  Iterator begin() { return Iterator{first_};  }  
  Iterator end()   { return Iterator{nullptr}; }
private:
  struct Elem
  {
    Elem(const T &v) : val_(v) { } 	  
    Elem *prev_ = nullptr;
    Elem *next_ = nullptr;    
    T     val_;
  };

  void copy(const List &rhs);
  void move(List &&rhs);
  void release();

  int   size_  = 0;   
  Elem *first_ = nullptr;
  Elem *last_  = nullptr;
};

template <typename T>
void List<T>::push_back(const T &i)
{
  Elem *p = new Elem{i};	
  if ( empty() )
  {
    first_ = last_ = p;	  
  }
  else
  {
    last_->next_ = p;
    p->prev_ = last_;
    last_ = p;
  }
  ++size_;
}

template <typename T>
void List<T>::pop_back()
{
  Elem *p = last_;
  --size_;
  if( empty() )  
  {
    first_ = last_ = nullptr;
  }
  else
  {
     last_ = p->prev_;
     last_->next_ = nullptr;     
  }
  delete p;
}

template <typename T>
void List<T>::copy(const List &rhs)
{
  Elem  *p = rhs.first_;
  while ( p )
  {
    push_back(p->val_);	  
    p = p->next_;
  }  
}

template <typename T>
void List<T>::move(List &&rhs)
{
  size_  = rhs.size_;  
  first_ = rhs.first_;
  last_  = rhs.last_;

  rhs.size_  = 0;
  rhs.first_ = nullptr;
  rhs.last_  = nullptr;
}

template <typename T>
void List<T>::release()
{
  size_ = 0;
  while ( first_ )
  {
    Elem *p = first_;	
    first_ = first_->next_;
    delete p;
  }
  last_ = nullptr;
}

template <typename T>
List<T>::List(const List &rhs)
{
  copy(rhs);
}

template <typename T>
List<T>::List(List &&rhs)
{
  move(std::move(rhs));	
}

template <typename T>
List<T>& List<T>::operator=(const List &rhs)
{
  if ( this != &rhs )
  {
     release();
     copy(rhs);     
  }
  return *this;  
}

template <typename T>
List<T>& List<T>::operator=(List &&rhs)
{
  if ( this != &rhs )
  {
     release();
     move(std::move(rhs));     
  }
  return *this;  
}

template <typename T>
List<T>::~List()
{
  release();	
}

#endif // LIST_H
