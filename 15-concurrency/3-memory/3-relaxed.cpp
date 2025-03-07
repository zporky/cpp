#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> x = 0;
std::atomic<int> y = 0;

int main()
{
  std::thread t2{[]{ std::cerr << y.load(std::memory_order_relaxed); 
	             std::cerr << x.load(std::memory_order_relaxed); } };	
  std::thread t1{[]{ x.store(1,std::memory_order_relaxed); 
	             y.store(2,std::memory_order_relaxed); } };	

  t1.join();
  t2.join();
}
