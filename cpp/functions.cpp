#include <iostream>
#include <vector>
#include "../headers/matrix.h"

void show_header(double version)
{
  std::cout << "Version " << version << std::endl;
  std::cout << "Matrix CLI" << std::endl;
}

void show_menu()
{
  std::cout << "\n\n-========================-\n\n";
  std::cout << "\t  Menu\n\n";
  std::cout << "1 - Add a matrix" << std::endl;
  std::cout << "2 - Show all matrices" << std::endl;
  std::cout << "3 - Trasport the matrix" << std::endl;
  std::cout << "\n\n-========================-\n\n";
}

Matrix create_matrix(int n, int m)
{
  Matrix matrix(n, m);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      std::cout << "A[" << i << "][" << j << "] = ";
      int elem;
      std::cin >> elem;

      matrix.set(elem, i, j);
    }

  return matrix;
}