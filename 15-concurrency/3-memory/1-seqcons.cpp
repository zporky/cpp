#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> x = 0;
std::atomic<int> y = 0;

int main()
{
  std::thread t1{[]{ x.store(1); y.store(2);} };	
  std::thread t2{[]{ std::cerr << y.load(); std::cerr << x.load();} };	

  t1.join();
  t2.join();
}
