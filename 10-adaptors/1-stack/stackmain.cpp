#include <iostream>
#include <stack>
//#include "stack.h"

int main()
{
  std::stack<int> st;	
  //Stack st;	
  for ( int i = 0; i <10; ++i)
  {
     st.push(i);
  }	  
  st.top() = 99;
  while ( ! st.empty() )
  {
    std::cout << st.top() << ' ';
    st.pop();    
  }
  std::cout << '\n';
  return 0;
}
