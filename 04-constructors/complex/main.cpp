#include <iostream>

#include "complex.h"

int main()
{
    Complex c1(5, -10);
    std::cout << c1 << '\n';

    Complex c2;
    c2 = c1;
    std::cout << c2 << '\n';
    c2 = ~c2;
    std::cout << c2 << '\n';

    // Complex c3 = add(c1, c2);
    Complex c3 = c1 + c2;
    std::cout << c3 << '\n';

    // c3 = subtract(c3, c2);
    c3 = c3 - c2;
    std::cout << c3 << '\n';

    double c2Abs = c2.abs();
    std::cout << "Absolute value: " << c2Abs << std::endl;
    c2.real() = 10;
    c2Abs = c2.abs();
    std::cout << "Absolute value: " << c2Abs << std::endl;

    const Complex c4(5, 7);
    // c4.display(); // error
}
