// Yusuf Pisan pisan@uw.edu
// 7 Jan 2018
//
// Simple testing of the Complex class

#include <iostream>

#include "complex.h"

using namespace std;

int main() {
    Complex c1(2, 5);
    Complex c2(3, -7);
    cout << boolalpha;
    cout << "c1 real: " << c1.getReal() << ", imaginary: " << c1.getImaginary() << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1==c2 should be false, got: " << (c1 == c2) << endl;
    cout << "c1!=c2 should be true, got: " << (c1 != c2) << endl;
    Complex c3 = c1 + c2;
    cout << "c3 as c1+c2: " << c3 << endl;
    Complex c4 = c1 * c2;
    cout << "c4 as c1*c2: " << c4 << endl;
    c4 += c1;
    cout << "c4 as c4+=c1: " << c4 << endl;
    c3 *= c1;
    cout << "c3 as c3*=c1: " << c3 << endl;
    cout << "c4>c3 should be true, got: " << (c4 > c3) << endl;
    cout << "c4<c3 should be false, got: " << (c4 < c3) << endl;
    c4.setReal(c3.getReal());
    cout << "c4 is now " << c4 << endl;
    cout << "c4>c3 should be false, got: " << (c4 > c3) << endl;
    cout << "c4<c3 should be true, got: " << (c4 < c3) << endl;
    return 0;
}
