#include <iostream>
#include <queue>
// #include "queue.h"

int main()
{
  std::queue<int> qt;
  // Queue qt{};	
  
  for ( int i = 1; i <10; ++i)
  {
     qt.push(i); // push_back
  }	  
  qt.front() = 0;
  qt.back()  = 99;
  while ( ! qt.empty() )
  {
    std::cout << qt.front() << ' ';
    qt.pop();   // pop_front   
  }
  std::cout << '\n';
  return 0;
}
