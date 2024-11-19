
#include <iostream>

int main()
{
  int n = 5;

  const int factn = [&] {
    int factn = 1;
    for (int i = 2; i <= n; ++i)
      factn *= i;
    return factn;
  }();	  

  std::cout << "fact(" << n << ") == " << factn << '\n';

  return 0;
}
