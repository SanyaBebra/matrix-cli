#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
#include "matrix.h"

class History
{
    std::vector<Matrix> history;

public:
    void print();
    void push(Matrix m);
    void transpose(int index);
    
    int size();
};

#endif