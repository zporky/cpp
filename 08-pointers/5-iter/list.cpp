#include <iostream>
#include "list.h"

void List::push_back(int i)
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

void List::pop_back()
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

void List::copy(const List &rhs)
{
  Elem  *p = rhs.first_;
  while ( p )
  {
    push_back(p->val_);	  
    p = p->next_;
  }  
}

void List::move(List &&rhs)
{
  size_  = rhs.size_;  
  first_ = rhs.first_;
  last_  = rhs.last_;

  rhs.size_  = 0;
  rhs.first_ = nullptr;
  rhs.last_  = nullptr;
}

void List::release()
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

List::List(const List &rhs)
{
  copy(rhs);
}

List::List(List &&rhs)
{
  move(std::move(rhs));	
}

List& List::operator=(const List &rhs)
{
  if ( this != &rhs )
  {
     release();
     copy(rhs);     
  }
  return *this;  
}

List& List::operator=(List &&rhs)
{
  if ( this != &rhs )
  {
     release();
     move(std::move(rhs));     
  }
  return *this;  
}


List::~List()
{
  release();	
}

