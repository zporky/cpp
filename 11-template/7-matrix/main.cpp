
#include <iostream>
#include <iomanip>
#include "matrix.h"

int main()
{	
  Matrix<int,10,20> m;

  int n = 0;
  for(int i = 0; i < m.rows(); ++i)
    for(int j = 0; j < m.cols(); ++j)
      m(i,j) = ++n;

  for(int i = 0; i < m.rows(); ++i)
  {
    for(int j = 0; j < m.cols(); ++j)
      std::cout << std::setw(4) << m(i,j);
    std::cout << '\n';
  }
/*
  Matrix<double,1,1> m1; std::cout << m1.rows() << m1.cols() << '\n';
  Matrix<char,1,1>   m2; std::cout << m2.rows() << m2.cols() << '\n';
  Matrix<unsigned char,1,1> m3; std::cout << m3.rows() << m3.cols() << '\n';
  Matrix<signed char,1,1> m4; std::cout << m4.rows() << m4.cols() << '\n';
  Matrix<float,1,1> m5; std::cout << m5.rows() << m5.cols() << '\n';
  Matrix<long double,1,1> m6; std::cout << m6.rows() << m6.cols() << '\n';
  Matrix<short,1,1> m7; std::cout << m7.rows() << m7.cols() << '\n';
  Matrix<long,1,1> m8; std::cout << m8.rows() << m8.cols() << '\n';
  Matrix<long long,1,1> m9; std::cout << m9.rows() << m9.cols() << '\n';
*/

  return 0;
}

