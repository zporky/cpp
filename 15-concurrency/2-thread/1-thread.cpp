#include <thread>
#include <chrono>
#include <string>
#include <iostream>
 
using namespace std::literals::chrono_literals;
 
void f( int i, const std::string& s)
{
  for( int i = 0; i < 10; ++i)
  {	  
    std::cout << i << ". " << s << '\n' << std::flush;
    std::this_thread::sleep_for(200ms);
  }
}
 
int main()
{
    int i = 0;
    std::string s{"working"};
    std::thread t(f, i, s); 
   
    std::cout << "main() is working ..." << '\n';
    std::this_thread::sleep_for(500ms);
    std::cout << "main() is waiting for thread..." << '\n';

    t.join();
    std::cout << "main() is exiting..." << '\n';
} 
