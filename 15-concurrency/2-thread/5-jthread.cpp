#include <thread>
#include <chrono>
#include <string>
#include <iostream>
 
using namespace std::literals::chrono_literals;
 
void f(std::stop_token st, int i, const std::string& s)
{
    while (!st.stop_requested())
    {
        std::cout << i++ << ". " << s << '\n' << std::flush;
        std::this_thread::sleep_for(200ms);
    }
}
 
int main()
{
    int i = 0;
    std::string s{"working"};
    std::jthread t(f, i, s); 
   
    std::stop_callback cb{t.get_stop_token(), []() { 
	    std::cout << "Stop requested" << std::endl; }};

    std::this_thread::sleep_for(3s);
    t.request_stop();
    std::this_thread::sleep_for(500ms);

    std::cout << "main() exiting ..." << '\n';
} 
