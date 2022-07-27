#include <iostream>
#include <iomanip>
#include <string>

#include "map.h"
#include "structs.h"
#include "twoDimensionalArray.h"

using namespace std;

void Map::displayMap(int userChoiceNumber)
{
    int numberOfColumns = mapSize.maxX - mapSize.minX + 1;
    int numberOfRows = mapSize.maxY - mapSize.minY + 1;

    int **p2DArray = Two_D_Array::allocate2DArray(numberOfRows, numberOfColumns);

    Two_D_Array::initialize2DArray(p2DArray, numberOfRows, numberOfColumns);
    Two_D_Array::assignValuesTo2DArray(p2DArray, userChoiceNumber);

    formatMap(p2DArray, numberOfRows, numberOfColumns, userChoiceNumber);

    Two_D_Array::delete2DArray(p2DArray, numberOfRows, numberOfColumns);
}

void Map::formatMap(int **p2DArray, int numberOfRows, int numberOfColumns, int userChoiceNumber)
{
    for (int i = (mapSize.maxY + 1); i >= (mapSize.minY - 2); i--)
    {
        ((i >= mapSize.minY) && (i <= mapSize.maxY)) ? printData(to_string(i)) : printData(" ");

        for (int j = (mapSize.minX - 1); j <= (mapSize.maxX + 1); j++)
        {
            int xCoordinate = calculateCoordinate(j, mapSize.minX);
            int yCoordinate = calculateCoordinate(i, mapSize.minY);

            if (i == (mapSize.minY - 2))
            {
                ((j == (mapSize.minX - 1)) || (j == mapSize.maxX + 1)) ? printData(" ") : printData(to_string(j));
            }
            else if ((j == mapSize.minX - 1) || (j == mapSize.maxX + 1) || (i == mapSize.minY - 1) || (i == mapSize.maxY + 1))
            {
                printData("#");
            }
            else if (p2DArray[yCoordinate][xCoordinate] != -1)
            {
                int value = p2DArray[yCoordinate][xCoordinate];
                print2DArrayValue(value, userChoiceNumber);
            }
            else
            {
                printData(" ");
            }
        }
        cout << endl;
    }
}

void Map::print2DArrayValue(int value, int userChoiceNumber)
{
    if (userChoiceNumber == 4 || userChoiceNumber == 6)
    {
        string LMH_symbol(1, getLMH_Symbol(value));
        printData(LMH_symbol);
    }
    else if (userChoiceNumber == 3 || userChoiceNumber == 5)
    {
        printData(to_string(value / 10));
    }
    else
    {
        printData(to_string(value));
    }
}

void Map::printData(string data)
{
    cout << right << setw(4) << data;
}

int Map::calculateCoordinate(int index, int minIdxrange)
{
    return (minIdxrange == 0) ? index : index + (0 - minIdxrange);
}

char Map::getLMH_Symbol(int value)
{
    if (value >= 0 && value < 35)
        return 'L';
    else if (value >= 35 && value < 65)
        return 'M';
    else
        return 'H';
}
