#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>  // <iosfwd> is enough

class Complex
{
public:
    Complex(double r = 0, double i = 0);

    double  real() const;
    double& real();
    double  imag() const;
    double& imag();

    double abs() const;

    void display(std::ostream& os);
private:
    double real_;  // real part
    double imag_;  // imag part
};

Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator~(Complex c);

std::ostream& operator<<(std::ostream& os, Complex c);

#endif // COMPLEX_H
