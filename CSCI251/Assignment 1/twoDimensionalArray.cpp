#include <iostream>

#include "twoDimensionalArray.h"
#include "structs.h"

using namespace std;

int **Two_D_Array::allocate(int rows, int cols)
{
    int **p2DArray = new int *[rows];

    for (int row = 0; row < rows; row++)
    {
        p2DArray[row] = new int[cols];
    }
    return p2DArray;
}

void Two_D_Array::initialize(int **p2DArray, int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            p2DArray[row][col] = -1;
        }
    }
}

void Two_D_Array::assignValues(int **p2DArray, int userChoiceNumber)
{
    if (userChoiceNumber == 2)
    {
        for (int i = 0; i < cityLocations_Vector.size(); i++)
        {
            int coordinatesX = calculateCoordinate(cityLocations_Vector[i].Xcoordinate, mapSize.minX);
            int coordinatesY = calculateCoordinate(cityLocations_Vector[i].Ycoordinate, mapSize.minY);

            p2DArray[coordinatesY][coordinatesX] = cityLocations_Vector[i].cityId;
        }
    }
    else if (userChoiceNumber == 3 || userChoiceNumber == 4)
    {
        for (int i = 0; i < cloudCovers_Vector.size(); i++)
        {
            int coordinatesX = calculateCoordinate(cloudCovers_Vector[i].Xcoordinate, mapSize.minX);
            int coordinatesY = calculateCoordinate(cloudCovers_Vector[i].Ycoordinate, mapSize.minY);
            p2DArray[coordinatesY][coordinatesX] = cloudCovers_Vector[i].cloudCoverValue;
        }
    }
    else
    {
        for (int i = 0; i < atmosphericPressures_Vector.size(); i++)
        {
            int coordinatesX = calculateCoordinate(atmosphericPressures_Vector[i].Xcoordinate, mapSize.minX);
            int coordinatesY = calculateCoordinate(atmosphericPressures_Vector[i].Ycoordinate, mapSize.minY);
            p2DArray[coordinatesY][coordinatesX] = atmosphericPressures_Vector[i].atmosphericPressureValue;
        }
    }
}

/*
If the IdxRange != 0, eg. the minimum X coordinate starts from  -1 or 1.
Hence, the function adjust it before inserting to the p2DArray.
*/
int Two_D_Array::calculateCoordinate(int coordinate, int minIdxrange)
{
    return (minIdxrange == 0) ? coordinate : coordinate + (0 - minIdxrange);
}

void Two_D_Array::clear(int **p2DArray, int rows, int cols)
{
    if (cols <= 0)
    {
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] p2DArray[i];
    }
    delete[] p2DArray;
}