#include <iostream>
#include <queue>
//#include "prioque.h"

int main()
{
  std::priority_queue<int> pq;	
  //  PrioQue pq;
  for ( auto i : { 4, 2, 6, 8, 2, 1, 9, 45, 12, 6, 7, 4, 34, 82 } )
    pq.push(i);

  while ( !pq.empty() )
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << '\n';
  return 0;
}
