// Yusuf Pisan pisan@uw.edu
// 7 Jan 2018
//
// Representing complex numbers using real and imaginary parts

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex {
    // Complex numbers written with real and imaginary part
    // Examples:
    // 5 + 2i
    // 7 - 3i
    // 0 + 4i
    // 12 + 0i
    friend ostream& operator<<(ostream& out, const Complex& c);
public:
    // constructor
    Complex(int real, int imaginary);
    // destructor
    virtual ~Complex();
    // get real part of the number
    int getReal() const;
    // set the real part
    void setReal(int real);
    // get imaginary part
    int getImaginary() const;
    // set imaginary part
    void setImaginary(int imaginary);
    // copy assignment
    // must check if it is a self assignment like 'c1 = c1'
    // returns *this
    Complex& operator=(const Complex& other);
    // true if both real and imaginary parts are ==
    bool operator==(const Complex& c) const;
    // true if real or imaginary parts different
    bool operator!=(const Complex& c) const;
    // add 2 complex numbers to each other
    Complex operator+(const Complex& c) const;
    // add a complex number to this one
    // returns *this
    Complex& operator+=(const Complex& c);
    // multiply 2 complex numbers
    Complex operator*(const Complex& c) const;
    // multiply a complex number to this one
    Complex& operator*=(const Complex& c);
    // > operator.
    // true if real part is greater than
    // or if real part is equal, imaginary part is greater than
    bool operator>(const Complex& c) const;
    // < operator.
    // true if real part is less than
    // or if real part is equal, imaginary part is less than
    bool operator<(const Complex& c) const;

private:
    int real;
    int imaginary;
};

#endif // COMPLEX_H
