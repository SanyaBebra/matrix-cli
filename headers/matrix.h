#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix
{
    int rows;
    int cols;
    std::vector<std::vector<int>> matrix;

public:
    Matrix(int size_n = 1, int size_m = 1);

    void print(); // ...

    bool set(int elem, int row, int col); // !!!

    void transpose();

    int getRows();
    int getCols();
};

#endif