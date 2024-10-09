#include <iostream>
#include <vector>
#include "matrix.h"

int main()
{
  Matrix m1 = { { // 2x5
    { 1, 2, 3, 4,  5 },
    { 6, 7, 8, 9, 10 }
  } };  
  Matrix m2 = { {  // 5x2
    { 1,  2 }, 
    { 3,  4 }, 
    { 5,  6 },
    { 7,  8 },
    { 9, 10 },
  } };
  const Matrix m3 = { { // 5x3
    {  1,  2,  3 }, 
    {  4,  5,  6 }, 
    {  7,  8,  9 },
    { 10, 11, 12 },
    { 13, 14, 15 },
  } };

  Matrix r1 = m1.mul(3);   // 2x5
  Matrix r6 = -5 * m1;     // 2x5
  Matrix r2 = m1.mul(m2);  // 2x2
  Matrix r3 = m2 * m1;     // 5x5
  Matrix r4 = m1 * m3;     // 2x3

  const Matrix res1 = { {  // 2x5
    {  3,  6,  9, 12, 15 },
    { 18, 21, 24, 27, 30 }
  } };  
  const Matrix res6 = { {  // 2x5
    {  -5, -10, -15, -20, -25 },
    { -30, -35, -40, -45, -50 }
  } };  
  const Matrix res2 = { {  // 2x2
    {  95, 110 },
    { 220, 260 }
  } };  
  const Matrix res3 = { {  // 5x5
    {  13,  16,  19,  22,  25 }, 
    {  27,  34,  41,  48,  55 },
    {  41,  52,  63,  74,  85 },
    {  55,  70,  85, 100, 115 },
    {  69,  88, 107, 126, 145 }
  } };  
  const Matrix res4 = { { // 2x3
    { 135, 150, 165 },
    { 310, 350, 390 }    
  } };

  if ( res1 == r1 && res6 == r6 && 
       res2 == r2 && res3 == r3 && 
       res4 == r4)
  {
    std::cerr << "Passed\n";
  }
  else  
  {
    std::cerr << "Failed\n";
  }
  return 0;	
}

