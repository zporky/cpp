#include <iostream>

int main()  
{
    const int ci = 10;
    int *ip = const_cast<int*>(&ci); // undefined behavior
    ++*ip;
    std::cout << ci << " " << *ip << '\n';   
    return 0;
}           
