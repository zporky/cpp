
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <typename T>
class Matrix
{
public:
  Matrix(int rows, int cols) 
    : rows_(rows), cols_(cols), v_(rows,std::vector<T>(cols)) { }	

  int rows() const { return rows_; }
  int cols() const { return cols_; }

  T&       operator()(int x, int y)       { return v_[x][y]; }
  const T& operator()(int x, int y) const { return v_[x][y]; }
private:	
  int rows_;
  int cols_;
  std::vector<std::vector<T>> v_;
};

#endif // MATRIX_H
