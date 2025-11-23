#include <iostream>
#include <vector>

void show_header(double version) {
  std::cout << "Version " << version << std::endl;
  std::cout << "Matrix CLI" << std::endl;
}

void show_menu() {
  std::cout << "\n\n-========================-\n\n";
  std::cout << "\t  Menu\n\n";
  std::cout << "1 - Add a matrix" << std::endl;
  std::cout << "2 - Show all matrices" << std::endl;
  // std::cout << "3 - Trasport the matrix" << std::endl;
  std::cout << "\n\n-========================-\n\n";
}

std::vector< std::vector<int> > create_matrix(int size) {
  std::vector< std::vector<int> > matrix(size, std::vector<int>(size)); 

    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) {
        std::cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
        std::cin >> matrix[i][j]; 
      }

    return matrix;
}