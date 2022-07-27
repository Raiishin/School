#ifndef MAP_H
#define MAP_H

#include <string>

namespace Map
{
    void displayMap(int userChoiceNumber);
    void formatMap(int **p2DArray, int noOfRows, int noOfCols, int userChoiceNumber);

    bool isXAxis(int i);
    bool isBorder(int i, int j);
    bool isWithinRange(int min, int max, int value);

    void print2DArrayValue(int value, int userChoiceNumber);
    void printData(std::string data);

    int calculateMapSize(int min, int max);
    int calculateCoordinate(int index, int minIdxrange);

    char getLMH_Symbol(int value);
}

#endif
