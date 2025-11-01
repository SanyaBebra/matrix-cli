#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// История всех матиц за время работы программы
vector<  vector<vector<int>>  > matrices_history; 

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

int main() {
  cout << "Version " << 1.1 << endl;

  cout << "Matrix" << endl;
  show_menu(); // Вывод меню

  int option = 0;
  cout << "Option: ";
  while (cin >> option) { // Выбор действия 
    if (option == 1) {
      cout << "Size of matrix: ";
      int size = 0;
      cin >> size;

      vector< vector<int> > matrix = create_matrix(size); 
      matrices_history.push_back(matrix);
      show_matrix(matrix);
    } else if (option == 2) {
      show_all_matrices(matrices_history);
    } else if (option == 3) {
      if (matrices_history.size() != 0) { // Выполнять если вектор не пустой
        // Выбрать матрицу
        cout << "Change a matrix by index: ";
        int matrix_index = 0;
        cin >> matrix_index;

        transpose_matrix(matrices_history[matrix_index]); // Транспортируем матрицу
      }
    }

    cout << "Option: ";
  }

  system("pause");
  return 0;
}