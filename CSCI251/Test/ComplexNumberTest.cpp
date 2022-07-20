#include <iostream>
#include <string>
#include <sstream>
#include "ComplexNumber.h"

using namespace std;

void testConstructors()
{
    ComplexNumber cn;
    cout << "-------------------------------" << endl;
    cout << "Test default constructor ..." << endl;
    cout << "-------------------------------" << endl;
    cout << "After 'ComplexNumber cn;', cn contains : " << endl;
    cout << cn.toString() << endl;

    ComplexNumber cn1(3, 8);
    cout << "-------------------------------" << endl;
    cout << "Test non-default constructor ..." << endl;
    cout << "-------------------------------" << endl;
    cout << "After 'ComplexNumber cn1 (3, 8);', cn1 contains : " << endl;
    cout << cn1.toString() << endl;

    ComplexNumber cn2(cn1);
    cout << "-------------------------------" << endl;
    cout << "Test copy constructor ..." << endl;
    cout << "-------------------------------" << endl;
    cout << "After 'ComplexNumber cn2 (cn1);', cn2 contains : " << endl;
    cout << cn2.toString() << endl;
}

void testOperators()
{
    ComplexNumber a(1, 2);
    ComplexNumber b(3, 4);

    cout << "After 'ComplexNumber a(1, 2);', a contains : " << endl
         << a.toString() << endl;
    cout << "After 'ComplexNumber b(3, 4);', a contains : " << endl
         << b.toString() << endl;

    ComplexNumber cn = a + b;
    cout << "Test + operator !!!" << endl;
    cout << "After 'ComplexNumber cn = a + b;', cn contains : " << endl
         << cn.toString() << endl;

    cout << "Test == operator !!!" << endl;
    cout << "Is a == b? Ans : " << boolalpha << (a == b) << endl;

    ComplexNumber cn1 = a + 5;
    cout << "Test ComplexNumber + int (member function) !!!" << endl;
    cout << "After 'ComplexNumber cn1 = a + 5', cn1 : " << cn1.toString() << endl;

    ComplexNumber cn2 = 5 + a;
    cout << "Test ComplexNumber + int (friend function) !!!" << endl;
    cout << "After 'ComplexNumber cn2 = 5 + a', cn2 : " << cn2.toString() << endl;

    ComplexNumber cn3;
    cout << endl;
    cout << "Test = (copy assignment) operator!!!" << endl;
    cout << "Initially, cn3 contains : " << cn3.toString() << endl;

    cn3 = cn2;

    cout << "After 'cn3 = cn2', cn3 contains : " << cn3.toString() << endl;
}

void testInsertionExtractionOperators()
{
    ComplexNumber cn;
    cin >> cn;
    cout << cn;
}

int main()
{
    testConstructors();
    //    testOperators ();
    //    testInsertionExtractionOperators ();
}
