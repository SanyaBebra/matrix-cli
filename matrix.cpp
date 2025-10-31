#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

// История всех матиц за время работы программы
vector<  vector<vector<int>>  > matrix_history; 

// Вывод меню
void view_menu() {
  cout << "\n\n-========================-\n\n";
  cout << "\t  Menu\n" << endl;
  cout << "1 - Add a matrix" << endl;
  cout << "2 - View all matrix" << endl;
  cout << "\n\n-========================-\n\n";
}

// Вывод матрицу
void view_matrix(const vector<vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) 
      cout << matrix[i][j] << '\t';

    cout << endl;
  }
}

void view_all_matrix(const vector< vector<vector<int>> > &history) {
  for (int i = 0; i < history.size(); i++) {
    cout << "Index " << i << ":" << endl;
    for (int row = 0; row < history[i].size(); row++) {

      for (int col = 0; col < history[i][row].size(); col++) 
        cout << history[i][row][col] << '\t';

      cout << "\n\n";
    }
    
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

int main() {
  cout << "Версия " << 1.0 << endl;

  cout << "Matrix" << endl;
  view_menu(); // Вывод меню

  int option = 0;
  cout << "Option: ";
  while (cin >> option) { // Выбор действия 
    if (option == 1) {
      cout << "Size of matrix: ";
      int size = 0;
      cin >> size;

      vector< vector<int> > matrix = create_matrix(size); 
      matrix_history.push_back(matrix);
      view_matrix(matrix);
    } else if (option == 2) {
      view_all_matrix(matrix_history);
    }

    cout << "Option: ";
  }

  system("pause");
  return 0;
}