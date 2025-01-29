#include <iostream>
#include <future>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

int f(int) 
{ 
  std::cout << "f is working...\n"; 
  std::this_thread::sleep_for(5000ms);
  return 42;
};

int main()
{
    std::future<int> the_answer = std::async(f,1);
    std::cout << "main is working...\n";
    std::this_thread::sleep_for(100ms);
    std::cout<< "main is calling get()\n" << the_answer.get() << std::endl;
}

