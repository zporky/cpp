#include <string>
#include <string_view>
#include <iostream>

int main()
{
  std::string_view sv{"Hello world", 8};
  std::cout << sv << '\n'; 
  sv = sv.substr(4);
  std::cout << sv << '\n';
  {
    sv = std::string{"hello"};
    //sv = std::string{"hello world let see this"};
    std::cout << sv << '\n';
  }
}

