
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class MatrixBase
{
public:
  MatrixBase(int rows, int cols) 
    : rows_(rows), cols_(cols) { }	

  int rows() const { return rows_; }
  int cols() const { return cols_; }
protected:
  int rows_;
  int cols_;
};

template <typename T>
class Matrix : public MatrixBase
{
public:
  Matrix(int rows, int cols) 
    : MatrixBase(rows,cols), v_(rows,std::vector<T>(cols)) { }	

  T&       operator()(int x, int y)       { return v_[x][y]; }
  const T& operator()(int x, int y) const { return v_[x][y]; }
private:	
  std::vector<std::vector<T>> v_;
};

#endif // MATRIX_H
