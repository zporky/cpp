#include <iostream>
#include <cassert>
#include "matrix.h"

void Matrix::print(std::ostream& os) const
{
  for ( size_t i = 0; i < rows(); ++i)
  {
    for ( size_t j = 0; j < cols(); ++j)
    {
      os << data_[i][j] << " ";	    
    }	    
    os << '\n';
  }
}

Matrix Matrix::mul(int c) const
{
  Matrix result = *this;
  for (size_t i = 0; i < result.rows(); ++i) 
  {
    for ( size_t j = 0; j < result.cols(); ++j)	  
    {
      result(i,j) *= c;	  
    }
  }
  return result;
}

Matrix Matrix::mul(const Matrix& right) const 
{
  assert(cols() == right.rows());

  std::vector<std::vector<int>> result; 
  for ( size_t i = 0; i < rows(); ++i)
  {
    std::vector<int> inner;
    for ( size_t j = 0; j < right.cols(); ++j)
    {
      size_t sum = 0;
      for ( size_t k = 0; k < cols(); ++k)
      {
        sum += data_[i][k]*right.data_[k][j];	      
      }      
      inner.push_back(sum);	    
    }
    result.push_back(inner);
  }
  return Matrix{result};	
}

Matrix operator*( int c, const Matrix& m)
{
  Matrix res{m};
  return res.mul(c);
}

Matrix operator+( const Matrix& m1, const Matrix& m2)
{
  assert( m1.cols() == 	m2.cols() && m1.rows() == m2.rows() );
  Matrix res{m1};
  for ( size_t i = 0; i < res.rows(); ++i)
    for( size_t j = 0; j < res.cols(); ++j)
    {
      res(i,j) += m2(i,j); 	    
    }
  return res;
}

Matrix operator-( const Matrix& m1, const Matrix& m2)
{
  assert( m1.cols() == 	m2.cols() && m1.rows() == m2.rows() );
  Matrix res{m1};
  for ( size_t i = 0; i < res.rows(); ++i)
    for( size_t j = 0; j < res.cols(); ++j)
    {
      res(i,j) -= m2(i,j); 	    
    }
  return res;
}

Matrix operator*( const Matrix& m1, const Matrix& m2)
{
  assert( m1.cols() == 	m2.rows() );
  Matrix res{m1};
  return res.mul(m2);
}

bool operator==( const Matrix& m1, const Matrix& m2)
{
  if ( m1.rows() != m2.rows() || m1.cols() != m2.cols() )
    return false;
  
  for ( size_t i = 0; i < m1.rows(); ++i)
    for( size_t j = 0; j < m1.cols(); ++j)
    {
      if ( m1(i,j) != m2(i,j) )
	return false; 	    
    }
  return true;
}
bool operator!=( const Matrix& m1, const Matrix& m2)
{
  return ! (m1 == m2 );
}

std::ostream& operator<<( std::ostream& os, const Matrix& m)
{
  m.print(os);
  return os;
}

