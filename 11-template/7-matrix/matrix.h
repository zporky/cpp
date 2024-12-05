
#ifndef MATRIX_H
#define MATRIX_H

#include <array>

template <typename T, int R, int C>
class Matrix
{
public:
  int rows() const { return R; }
  int cols() const { return C; }

  T&       operator()(int x, int y)       { return v_[x][y]; }
  const T& operator()(int x, int y) const { return v_[x][y]; }
private:	
  std::array<std::array<T,C>,R> v_;
};

#endif // MATRIX_H
