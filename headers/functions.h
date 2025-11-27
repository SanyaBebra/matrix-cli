#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include "matrix.h"
#include "history.h"

void show_header(double version);
void show_menu();
Matrix create_matrix(int n, int m);
void operation(History& h, void (Matrix::*method)());

#endif