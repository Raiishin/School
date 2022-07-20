#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string **array2D = nullptr;

void init2Darray(int col, int row)
{
    array2D = new string *[row];

    for (int i = 0; i < row; i++)
        array2D[i] = new string[col];
}

void populate2DArray(int col, int row)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            ostringstream oss;
            oss << "x" << j + 1 << "y" << row - i;

            array2D[i][j] = oss.str();
        }
}

void display2DArray(int col, int row)
{
    cout << endl;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cout << array2D[i][j] << ", ";

    cout << endl;
}

void safelyDeallocateMemory(int col, int row)
{
    if (col <= 0)
        return;

    for (int i = 0; i < row; i++)
        delete[] array2D[i];

    delete[] array2D;
}

int main()
{
    int row, col;
    row = col = 0;

    cout << "Pls enter no. of cols : ";
    cin >> col;
    cout << endl;

    cout << "Pls enter no. of rows : ";
    cin >> row;
    cout << endl;

    init2Darray(col, row);
    populate2DArray(col, row);
    display2DArray(col, row);
    safelyDeallocateMemory(col, row);

    cout << endl;

    return 0;
}