//a complex.cc file that contains the implementations of method and functions declared in the complex class
#include "../CS280/complex.h"

ostream &operator<<(ostream &out, const Complex &c)
{
    if (c.real == 0 && c.img == 0) {
        out << 0;
    } else if (c.real == 0) {
        out << c.img << "j";
    } else if (c.img == 0) {
        out << c.real;
    } else if (c.img > 0) {
        if (c.img == 1) {
            out << c.real << "+j";
        } else {
            out << c.real << "+" << c.img << "j";
        }
    } else {
        if (c.img == -1) {
            cout << c.real << "-j";
        } else {
            out << c.real << c.img << "j";
        }
    }
    return out;
}

Complex::Complex(double real, double img) :
        real(real), img(img)
{
}

Complex::Complex(double real) :
        real(real), img(0)
{
}

Complex::~Complex()
{
}

// operator overloading
Complex Complex::operator+(const Complex &that) const
{
    return Complex(this->real + that.real, this->img + that.img);
}

Complex Complex::operator-(const Complex &that) const
{
    return Complex(this->real - that.real, this->img - that.img);
}

Complex Complex::operator*(const Complex &that) const
{
    double real = this->real * that.real - this->img * that.imh;
    double img = this->real * that.img + this->img * that.real;
    return Complex(real, img);
}

Complex Complex::operator/(const Complex &that) const
{
    Complex result = *this * Complex(that.real, -that.img);
    double abs = that.real * that.real + that.img * that.img;
    result.real /= abs;
    result.img /= abs;
    return result;
}

Complex operator+(const double x, const Complex &that)
{
    return that + x;
}

Complex operator-(const double x, const Complex &that)
{
    return Complex(x) - that;
}

Complex operator*(const double x, const Complex &that)
{
    return that * x;
}

Complex operator/(const double x, const Complex &that)
{
    return Complex(x) / that;
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImg() const
{
    return img;
}

