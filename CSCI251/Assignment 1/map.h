#ifndef MAP_H
#define MAP_H

#include <string>

namespace Map
{
    void displayMap(int userChoiceNumber);
    void formatMap(int **p2DArray, int noOfRows, int noOfCols, int userChoiceNumber);

    void print2DArrayValue(int value, int userChoiceNumber);
    void printData(std::string data);

    int calculateCoordinate(int index, int minIdxrange);

    char getLMH_Symbol(int value);
}

#endif
