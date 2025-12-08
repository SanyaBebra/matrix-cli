#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "matrix.h"
#include "history.h"

void show_menu();
Matrix create_matrix(int n, int m);
void operation(History &history, void (Matrix::*method)());
void operation(History &history, void (Matrix::*method)(int), int number);
void operation(History &history, void (Matrix::*method)(Matrix &m), int index_1, int index_2);

#endif