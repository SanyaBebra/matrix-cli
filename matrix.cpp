#include <iostream>
#include <cstdlib>
#include <vector>
#include "functions.h"
using namespace std;

// История всех матиц за время работы программы
vector<  vector<vector<int>>  > matrices_history; 

int main() {
  show_header(1.2);
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