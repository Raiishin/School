#ifndef TWO_D_ARRAY_H
#define TWO_D_ARRAY_H

namespace Two_D_Array
{
    int **allocate(int rows, int cols);
    void initialize(int **p2DArray, int rows, int cols);
    void assignValues(int **p2DArray, int userChoiceNumber);
    int calculateCoordinate(int coordinate, int minIdxrange);
    void clear(int **p2DArray, int rows, int cols);
}
#endif