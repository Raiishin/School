#include <iostream>
#include <string>

using namespace std;

void testPtr1()
{
    cout << endl;
    cout << "Inside testPtr1 () !!! " << endl;

    int intVar = 38;
    int *intPtr = nullptr;

    cout << endl;
    cout << "Before initializing pointer (int * intPtr = nullptr...)" << endl;
    cout << endl;

    cout << "intVar's address (&intVar) : " << &intVar << endl;
    cout << "intVar's contents (intVar) : " << intVar << endl;
    cout << "intPtr's address (&intPtr) : " << &intPtr << endl;
    cout << "intPtr's contents (intPtr) : " << intPtr << endl;

    cout << endl;
    cout << "After initializing pointer (intPtr = new int (168) ...)" << endl;
    cout << endl;

    intPtr = new int(168);

    cout << "intVar's address (&intVar) : " << &intVar << endl;
    cout << "intVar's contents (intVar) : " << intVar << endl;
    cout << "intPtr's address (&intPtr) : " << &intPtr << endl;
    cout << "intPtr's contents (intPtr) : " << intPtr << endl;

    cout << "contents of what intPtr is pointing to (*intPtr) : " << *intPtr << endl;
    cout << "address of contents of what intPtr is pointing to (&(*intPtr)) : " << &(*intPtr) << endl;
    cout << endl;
}

void testPtr2()
{
    cout << endl;
    cout << "Inside testPtr2 () !!! " << endl;

    int intVar = 138;
    int *intPtr = nullptr;

    cout << endl;
    cout << "Setting intPtr = &intVar ..." << endl;
    cout << endl;

    intPtr = &intVar;

    cout << "intVar's address (&intVar) : " << &intVar << endl;
    cout << "intVar's contents (intVar) : " << intVar << endl;
    cout << "intPtr's address (&intPtr) : " << &intPtr << endl;
    cout << "intPtr's contents (intPtr) : " << intPtr << endl;
    cout << "contents of what intPtr is pointing to (*intPtr) : " << *intPtr << endl;

    cout << endl;
    cout << "Setting intPtr = new int (368) ..." << endl;
    cout << endl;

    intPtr = new int(368);

    cout << "intVar's address (&intVar) : " << &intVar << endl;
    cout << "intVar's contents (intVar) : " << intVar << endl;
    cout << "intPtr's address (&intPtr) : " << &intPtr << endl;
    cout << "intPtr's contents (intPtr) : " << intPtr << endl;
    cout << "contents of what intPtr is pointing to (*intPtr) : " << *intPtr << endl;
    cout << "address of contents of what intPtr is pointing to (&(*intPtr)) : " << &(*intPtr) << endl;
    cout << endl;
}

void testRef()
{
    cout << endl;
    cout << "Inside testRef () !!! " << endl;

    cout << endl;
    cout << "In the beginning ..." << endl;
    cout << endl;

    int intVar1 = 38;
    int intVar2 = 68;
    int intVar3 = 98;

    int &alias = intVar1;

    cout << "intVar1's address (&intVar1) : " << &intVar1 << endl;
    cout << "intVar1's contents (intVar1) : " << intVar1 << endl;
    cout << "intVar2's address (&intVar2) : " << &intVar2 << endl;
    cout << "intVar2's contents (intVar2) : " << intVar2 << endl;
    cout << "intVar3's address (&intVar3) : " << &intVar3 << endl;
    cout << "intVar3's contents (intVar3) : " << intVar3 << endl;
    cout << "alias's address (&alias) : " << &alias << endl;
    cout << "alias's contents (alias) : " << alias << endl;

    cout << endl;
    cout << "Setting intVar1 = 138 ..." << endl;
    cout << endl;

    intVar1 = int(138);

    cout << "intVar1's address (&intVar1) : " << &intVar1 << endl;
    cout << "intVar1's contents (intVar1) : " << intVar1 << endl;
    cout << "intVar2's address (&intVar2) : " << &intVar2 << endl;
    cout << "intVar2's contents (intVar2) : " << intVar2 << endl;
    cout << "intVar3's address (&intVar3) : " << &intVar3 << endl;
    cout << "intVar3's contents (intVar3) : " << intVar3 << endl;
    cout << "alias's address (&alias) : " << &alias << endl;
    cout << "alias's contents (alias) : " << alias << endl;

    cout << endl;
    cout << "Setting alias = 1638 ..." << endl;
    cout << endl;

    alias = int(1638);

    cout << "intVar1's address (&intVar1) : " << &intVar1 << endl;
    cout << "intVar1's contents (intVar1) : " << intVar1 << endl;
    cout << "intVar2's address (&intVar2) : " << &intVar2 << endl;
    cout << "intVar2's contents (intVar2) : " << intVar2 << endl;
    cout << "intVar3's address (&intVar3) : " << &intVar3 << endl;
    cout << "intVar3's contents (intVar3) : " << intVar3 << endl;
    cout << "alias's address (&alias) : " << &alias << endl;
    cout << "alias's contents (alias) : " << alias << endl;

    cout << endl;
}

int main()
{
    testPtr1();
    testPtr2();
    testRef();

    cout << endl;
    return (0);
}