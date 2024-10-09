
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>


class Matrix
{
public:	
  Matrix(const std::vector<std::vector<int>>& vv) : data_(vv) { }

  size_t rows() const { return data_.size(); }	
  size_t cols() const { return data_.size() > 0 ? data_[0].size() : 0; }	
  void print(std::ostream&  os) const; // helper to print

  Matrix mul(int c) const;
  Matrix mul(const Matrix& m) const;

  int& operator()(int i, int j)       { return data_[i][j]; }
  int  operator()(int i, int j) const { return data_[i][j]; }
private:
  std::vector<std::vector<int>> data_; 	
};

Matrix operator*( int, const Matrix& m);
Matrix operator+( const Matrix& m1, const Matrix& m2);
Matrix operator-( const Matrix& m1, const Matrix& m2);
Matrix operator*( const Matrix& m1, const Matrix& m2);

bool operator==( const Matrix& m1, const Matrix& m2);
bool operator!=( const Matrix& m1, const Matrix& m2);

std::ostream& operator<<( std::ostream& os, const Matrix& m);

#endif // MATRIX_H
