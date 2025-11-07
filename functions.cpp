#include <iostream>
#include <vector>
using namespace std;

void show_header(double version) {
  cout << "Version " << version << endl;
  cout << "Matrix CLI" << endl;
}

// Вывод меню
void show_menu() {
  cout << "\n\n-========================-\n\n";
  cout << "\t  Menu\n" << endl;
  cout << "1 - Add a matrix" << endl;
  cout << "2 - Show all matrices" << endl;
  cout << "3 - Trasport the matrix" << endl;
  cout << "\n\n-========================-\n\n";
}

// Вывод матрицы
void show_matrix(const vector<vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) 
      cout << matrix[i][j] << '\t';

    cout << "\n\n";
  }
}

// Вывод всех матриц
void show_all_matrices(const vector< vector<vector<int>> > &history) {
  for (int i = 0; i < history.size(); i++) {
    cout << "Index " << i << ":" << endl;
    show_matrix(history[i]);
  }
}

// Создает и возвращает новую матрицу
vector< vector<int> > create_matrix(int size) {
  vector< vector<int> > matrix(size, vector<int>(size)); // Создается новый двумерный массив

    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) {
        cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
        cin >> matrix[i][j]; // Записываем в новый массив данные, это наша матрица
      }

    return matrix; // Возвращаем готовую матрицу
}

// Транспоитрует матрицу
void transpose_matrix(vector< vector<int> > &matrix) {
  vector<vector<int>> transpose = matrix;

  for (int i = 0; i < matrix.size(); i++) 
    for (int j = 0; j < matrix.size(); j++) 
      matrix[i][j] = transpose[j][i];
}