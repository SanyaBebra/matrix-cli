#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
using namespace std;

void show_header(double version);
void show_menu();
void show_matrix(const vector<vector<int>> &matrix);
void show_all_matrices(const vector< vector<vector<int>> > &history);
vector< vector<int> > create_matrix(int size);
void transpose_matrix(vector< vector<int> > &matrix);

#endif