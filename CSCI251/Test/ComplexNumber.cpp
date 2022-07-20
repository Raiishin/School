#include "ComplexNumber.h"

// --------------------------------------
// placed in ComplexNumber.cpp
// --------------------------------------
ComplexNumber::ComplexNumber()
{
    real = img = 0;
}

ComplexNumber::ComplexNumber(const ComplexNumber &anotherObj)
{
    real = anotherObj.real;
    img = anotherObj.img;
}

ComplexNumber::ComplexNumber(int rl, int im)
{
    real = rl;
    img = im;
}

string ComplexNumber::toString()
{
    ostringstream oss;
    oss << "obj : " << this << ", real : " << real << ", img : " << img << endl;
    return (oss.str());
}

/*
// ---------------------------------------------------
// Operator overloading of +, (friend function)
// ---------------------------------------------------
ComplexNumber operator+( const ComplexNumber& lhs, const ComplexNumber& rhs)
{
    ComplexNumber result;

    result.real = lhs.real + rhs.real;
    result.img  = lhs.img + rhs.img;
    return result;
}
*/

// ---------------------------------------------------
// Operator overloading of +, (member function)
// ---------------------------------------------------
ComplexNumber ComplexNumber::operator+(const ComplexNumber &rhs) const
{
    ComplexNumber result;
    result.real = real + rhs.real;
    result.img = img + rhs.img;
    return result;
}

// ---------------------------------------------------
// Operator overloading of ==, (member function)
// ---------------------------------------------------
bool ComplexNumber::operator==(const ComplexNumber &rhs) const
{
    bool realValuesEqual = (real == rhs.real);
    bool imgValuesEqual = (img == rhs.img);

    return (realValuesEqual && imgValuesEqual);
}

// ---------------------------------------------------
// Operator overloading of ComplexNumber + int (member function)
// ---------------------------------------------------
ComplexNumber ComplexNumber::operator+(int rhs)
{
    ComplexNumber result;
    result.real = real + rhs;
    result.img = img + rhs;
    return result;
}

// ---------------------------------------------------
// Operator overloading of int + ComplexNumber (friend function)
// ---------------------------------------------------
ComplexNumber operator+(int lhs, const ComplexNumber &rhs)
{
    ComplexNumber result;
    result.real = rhs.real + lhs;
    result.img = rhs.img + lhs;
    return result;
}

// ---------------------------------------------------
// Operator overloading of =, (member function)
// ---------------------------------------------------
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &rhs)
{
    if (this != &rhs)
    {
        this->real = rhs.real;
        this->img = rhs.img;
    }

    return (*this);
}

// ---------------------------------------------------
// Operator overloading of <<, (friend function)
// ---------------------------------------------------
ostream &operator<<(ostream &os, ComplexNumber &cn)
{
    os << "Real : " << cn.real << ", ";
    os << "Img : " << cn.img << endl;

    // OR ...
    // os << cn.toString();

    return os;
}

// ---------------------------------------------------
// Operator overloading of >>, (friend function)
// ---------------------------------------------------
istream &operator>>(istream &is, ComplexNumber &cn)
{
    cout << "Pls enter real no. : ";
    is >> cn.real;
    cout << "Pls enter img no.  : ";
    is >> cn.img;
    cout << endl;

    return is;
}
