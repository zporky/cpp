#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

int main()
{
  std::vector<int> v;
  int d;

  auto start = std::chrono::system_clock::now();  // start timer
  while ( std::cin >> d )
  {
    v.push_back(d);                // append element
  }  
  std::sort(v.begin(), v.end());   // sort elements
  auto end = std::chrono::system_clock::now();  // stop timer

  for ( int i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";

  const std::chrono::duration<double> elapsed = end - start;					
  std::cerr << "\nsorted " << v.size() << " elements, ";
  std::cerr << "elapsed time = " << elapsed.count() << "s\n";
  //std::cerr << "elapsed time = " << elapsed         << "s\n"; // C++20

  return 0;
}
