//a complex.h file that contains the declaration of the complex class

#ifndef CS280_COMPLEX_H
#define CS280_COMPLEX_H

#include <iostream>

using namespace std;
class Complex {

private:
    double real;
    double virl;
public:
    Complex(double real, double img);
//converts a double to Complex
    Complex(double real);
    ~Complex();

// operator overloading
    Complex operator+(const Complex &that) const;
    Complex operator-(const Complex &that) const;
    Complex operator*(const Complex &that) const;
    Complex operator/(const Complex &that) const;
    friend Complex operator+(const double x, const Complex &that);
    friend Complex operator-(const double x, const Complex &that);
    friend Complex operator*(const double x, const Complex &that);
    friend Complex operator/(const double x, const Complex &that);
    friend ostream &operator<<(ostream &out, const Complex &c);
    double getReal() const;
    double getImg() const;
};

#endif //CS280_COMPLEX_H
