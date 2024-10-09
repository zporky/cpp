#include <iostream>
#include <cmath>
#include <iostream>

#include "complex.h"

Complex::Complex(double r, double i) : real_(r), imag_(i) { }

double Complex::abs() const
{
    return std::sqrt(std::pow(imag(), 2) + std::pow(real(), 2));
}
double Complex::real() const
{
    return real_;
}
double& Complex::real()
{
    return real_;
}
double Complex::imag() const
{
    return imag_;
}
double& Complex::imag()
{
    return imag_;
}
void Complex::display(std::ostream& os)
{
    std::cout << real();

    if (imag_ > 0)
    {
        os << " + ";
        if (imag_ == 1)
        {
            os << "i";
        }
        else
        {
            os << imag_ << "i";
        }
    }
    else if (imag_ < 0 )
    {
        if (imag_ == -1)
        {
            os << " - i";
        }
        else
        {
            os << imag_ << "i";
        }
    }
 //   std::cout << std::endl;
}

Complex operator+(Complex a, Complex b)
{
    return Complex{ a.real()+b.real(), a.imag()+b.imag()};
}
Complex operator-(Complex a, Complex b)
{
    return Complex{ a.real()-b.real(), a.imag()-b.imag()};
}
Complex operator~(Complex c)
{
    return Complex{ c.real(), -c.imag()};
}
std::ostream& operator<<(std::ostream& os, Complex c)
{
    c.display(os);
    return os;
}

