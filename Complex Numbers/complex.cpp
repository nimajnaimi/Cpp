//Name: Nima Naimi
//Date: January 28, 2018
//Assignment #4: Complex Numbers
//Description: Implements operator functions for complex numbers

#include "complex.h"

// constructor
Complex::Complex(int real, int imaginary) : real{real}, imaginary{imaginary}
{}

// destructor
Complex::~Complex()
{}

// Complex numbers written with real and imaginary part
ostream& operator<<(ostream& out, const Complex& c)
{
    cout << c.real << " ";
    if (c.imaginary < 0)
    {
        cout << "-";
    }
    else
    {
        cout << "+";
    }
    cout << " " << abs(c.imaginary) << "i";
    return out;
}

// sets the object's real and imaginary values to the ones passed
Complex& Complex::operator=(const Complex& other)
{
    if (real != other.real)
    {
        real = other.real;
    }
    if (imaginary != other.imaginary)
    {
        imaginary = other.imaginary;
    }
    return *this;
}

// true if both real and imaginary parts are equal
bool Complex::operator==(const Complex& c) const
{
    return real == c.real && imaginary == c.imaginary;
}

// true if real or imaginary parts different
bool Complex::operator!=(const Complex& c) const
{
    return real != c.real || imaginary != c.imaginary;
}

// add 2 complex numbers to each other. Returns a new complex object
Complex Complex::operator+(const Complex& c) const
{
    return Complex(real + c.real, imaginary + c.imaginary);
}

// add a complex number to the object's one
Complex& Complex::operator+=(const Complex& c)
{
    real += c.real;
    imaginary += c.imaginary;
    return *this;
}

// multiply 2 complex numbers. Returns a new complex object
Complex Complex::operator*(const Complex& c) const
{
    return Complex (real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}

// multiply a complex number to the object's one
Complex& Complex::operator*=(const Complex& c)
{
    int real_temp{real * c.real - imaginary * c.imaginary};
    imaginary = real * c.imaginary + imaginary * c.real;
    real = real_temp;
    return *this;
}

bool Complex::operator>(const Complex& c) const
{
   return real > c.real || (real == c.real && imaginary > c.imaginary);
}

// true if real part is less than or if real part is equal, imaginary part
// is less than
bool Complex::operator<(const Complex& c) const
{
   return real < c.real || (real == c.real && imaginary < c.imaginary);
}

// Returns the real part of the complex number
int Complex::getReal() const
{
    return real;
}

// Sets the real part of the complex number to the passed value
void Complex::setReal(int real)
{
    this->real = real;
}

// Returns the imaginary part of the complex number
int Complex::getImaginary() const
{
    return imaginary;
}

// Sets the imaginary part of the complex number to the passed value
void Complex::setImaginary(int imaginary)
{
    this->imaginary = imaginary;
}
