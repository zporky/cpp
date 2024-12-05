
#include <iostream>
#include <iomanip>
#include "matrix.h"

int main()
{	
  Matrix<int> m{10,20};

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
  Matrix<double> m1(1,1); std::cout << m1.rows() << m1.cols() << '\n';
  Matrix<char>   m2(1,1); std::cout << m2.rows() << m2.cols() << '\n';
  Matrix<unsigned char> m3(1,1); std::cout << m3.rows() << m3.cols() << '\n';
  Matrix<signed char> m4(1,1); std::cout << m4.rows() << m4.cols() << '\n';
  Matrix<float> m5(1,1); std::cout << m5.rows() << m5.cols() << '\n';
  Matrix<long double> m6(1,1); std::cout << m6.rows() << m6.cols() << '\n';
  Matrix<short> m7(1,1); std::cout << m7.rows() << m7.cols() << '\n';
  Matrix<long> m8(1,1); std::cout << m8.rows() << m8.cols() << '\n';
  Matrix<long long> m9(1,1); std::cout << m9.rows() << m9.cols() << '\n';
*/

  return 0;
}

