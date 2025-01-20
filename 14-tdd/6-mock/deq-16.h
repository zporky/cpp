#ifndef DEQ_H
#define DEQ_H

#include <cstddef>
#include <vector>
#include <array>
#include <memory>
#include <stdexcept>
//#include <iostream>

static const size_t ChunkSize_ = 16; 

template <typename T, typename CONT = std::vector<std::unique_ptr<std::array<T,ChunkSize_>>>>
class Deq
{
public:
  using ChunkType = std::array<T,ChunkSize_>;

  size_t size()  const { return size_; } 	
  size_t empty() const { return 0 == size(); } 	
  
  void push_back( const T& t);
  void pop_back();

  void push_front( const T& t);
  void pop_front();

  T&   front();
  const T&   front() const;
  T&   back();
  const T&   back()  const; 

  T&   operator[](size_t idx) noexcept;
  const T&   operator[](size_t idx) const noexcept;
  T&   at(size_t idx);
  const T&   at(size_t idx) const;

#ifdef TEST_ONLY
  CONT& getChunks() { return chunks_; }
#endif  
  
private:
  size_t endPos() const  { return (offset_+size_) % ChunkSize_; }
  size_t backPos() const { return (offset_+size_+ChunkSize_-1) % ChunkSize_; }
  size_t bufno(size_t idx) const { return (offset_+idx) / ChunkSize_; }
  size_t bufix(size_t idx) const { return (offset_+idx) % ChunkSize_; }
  void   checkIndex(size_t idx) const; // may throw std::out_of_range

  size_t                                  size_   = 0;
  size_t                                  offset_ = 0;

  CONT  chunks_{};
};

template <typename T, typename BASE>
void Deq<T,BASE>::push_back( const T& t) 
{
  if ( chunks_.size() == bufno(size_) )
  {
    chunks_.push_back(std::make_unique<ChunkType>());
  }	  
  (*chunks_[bufno(size_)])[bufix(size_)] = t;
  ++size_;
}

template <typename T, typename BASE>
void Deq<T,BASE>::push_front( const T& t)
{
  if ( 0 == offset_)
  {
    chunks_.insert(chunks_.begin(), std::make_unique<ChunkType>());
    offset_ = ChunkSize_;    
  }
  --offset_;
  (*chunks_[0])[offset_] = t;
  ++size_;
}

template <typename T, typename BASE>
void Deq<T,BASE>::pop_back()
{
  --size_;
}

template <typename T, typename BASE>
void Deq<T,BASE>::pop_front()
{
  ++offset_;
  if ( ChunkSize_ == offset_ )
  {
    offset_ = 0;
    chunks_.erase(chunks_.begin());    
  }  
  --size_;
}

template <typename T, typename BASE>
T& Deq<T,BASE>::front() 
{
  return (*chunks_.front())[offset_];	
}

template <typename T, typename BASE>
T& Deq<T,BASE>::back()
{
  return (*chunks_[bufno(size_-1)])[backPos()];	
}

template <typename T, typename BASE>
const T& Deq<T,BASE>::front() const
{
  return (*chunks_.front())[offset_];	
}

template <typename T, typename BASE>
const T& Deq<T,BASE>::back() const
{
  return (*chunks_[bufno(size_-1)])[backPos()];	
}

template <typename T, typename BASE>
T& Deq<T,BASE>::operator[](size_t idx) noexcept
{
  return (*chunks_[bufno(idx)])[bufix(idx)];
}

template <typename T, typename BASE>
const T& Deq<T,BASE>::operator[](size_t idx) const noexcept
{
  return (*chunks_[bufno(idx)])[bufix(idx)];
}

template <typename T, typename BASE>
T& Deq<T,BASE>::at(size_t idx)
{
  checkIndex(idx);	
  return (*chunks_[bufno(idx)])[bufix(idx)];
}

template <typename T, typename BASE>
const T& Deq<T,BASE>::at(size_t idx) const
{
  checkIndex(idx);	
  return (*chunks_[bufno(idx)])[bufix(idx)];
}

template <typename T, typename BASE>
void Deq<T,BASE>::checkIndex(size_t idx) const
{
  if ( idx >= size_ )	
    throw std::out_of_range{"bad index"};
}

#endif // DEQ_H
