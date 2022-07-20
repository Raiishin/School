#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// --------------------------------------
// placed in ComplexNumber.h
// --------------------------------------
class ComplexNumber
{
    // friend ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend ComplexNumber operator+(int lhs, const ComplexNumber &rhs);
    friend ostream &operator<<(ostream &os, ComplexNumber &cn);
    friend istream &operator>>(istream &is, ComplexNumber &cn);

private:
    int real;
    int img;

public:
    ComplexNumber();
    ComplexNumber(const ComplexNumber &anotherObj);
    ComplexNumber(int rl, int im);
    string toString();

    ComplexNumber operator+(const ComplexNumber &rhs) const;
    bool operator==(const ComplexNumber &rhs) const;

    ComplexNumber operator+(int rhs);

    ComplexNumber &operator=(const ComplexNumber &rhs);
};

#endif
