#ifndef DEQ_H
#define DEQ_H

#include <cstddef>
#include <vector>
#include <array>

template <typename T>
class Deq
{
public:
  static const size_t ChunkSize_ = 16; 

  size_t size()  { return size_; } 	
  size_t empty() { return 0 == size(); } 	
private:

  size_t                                  size_;
  std::vector<std::array<T,ChunkSize_> *> chunks_;
};

#endif // DEQ_H
