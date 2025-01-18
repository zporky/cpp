#ifndef DEQ_H
#define DEQ_H

#include <cstddef>
#include <vector>
#include <array>
#include <memory>

template <typename T>
class Deq
{
public:
  static const size_t ChunkSize_ = 16; 
  using ChunkType = std::array<T,ChunkSize_>;

//  Deq(const Deq& rhs);
//  Deq& operator=(const Deq& rhs);

  size_t size()  const { return size_; } 	
  size_t empty() const { return 0 == size(); } 	
  
  void push_back( const T& t);
  void pop_back();

  T&   front();
  T&   back();

  T&   operator[](size_t idx) noexcept;
  T&   at(size_t idx);
  
//  const T&   front() const;
//  const T&   back()  const; 
private:
  size_t endPos() const  { return (size_) % ChunkSize_; }
  size_t backPos() const { return (size_+ChunkSize_-1) % ChunkSize_; }
  size_t bufno(size_t idx) const { return (idx) / ChunkSize_; }
  size_t bufix(size_t idx) const { return (idx) % ChunkSize_; }

  size_t                                  size_{};
  std::vector<std::unique_ptr<ChunkType>> chunks_{};
};

template <typename T>
void Deq<T>::push_back( const T& t) 
{
  if ( ChunkSize_*chunks_.size() == size_ )
  {
    chunks_.push_back(std::make_unique<ChunkType>());	  
  }	  
  (*chunks_[bufno(size_)])[bufix(size_)] = t;
  ++size_;
}

template <typename T>
void Deq<T>::pop_back()
{
  --size_;
}

template <typename T>
T& Deq<T>::front() 
{
  return (*chunks_.front())[0];	
}

template <typename T>
T& Deq<T>::back()
{
  return (*chunks_.back())[bufix(size_-1)];	
}

template <typename T>
T& Deq<T>::operator[](size_t idx) noexcept
{
  return (*chunks_[bufno(idx)])[bufix(idx)];
}

/*
template <typename T>
const T& Deq<T>::front() const
{
  return (*chunks_.front())[0];	
}

template <typename T>
const T& Deq<T>::back() const
{
  return (*chunks_.back())[bufix(size_-1)];	
}
*/

#endif // DEQ_H
