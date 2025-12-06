#include <iostream>
#include <vector>
#include "../headers/matrix.h"
#include "../headers/history.h"

void show_menu()
{
  std::cout << "\n\n-========================-\n\n";
  std::cout << "\t  Menu\n\n";
  std::cout << "1 - Add" << std::endl;
  std::cout << "2 - Show all" << std::endl;
  std::cout << "3 - Traspose" << std::endl;
  std::cout << "4 - Take out minus" << std::endl;
  std::cout << "5 - Multiply on the number" << std::endl;
  std::cout << "0 - Exit" << std::endl;
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

void operation(History &history, void (Matrix::*method)())
{
  std::cout << "Change matrix: " << std::endl;
  history.print();

  std::cout << "Index: ";
  int index;
  std::cin >> index;

  if (index > 0 && index <= history.size())
    (history.get(index - 1).*method)();
}

void operation(History &history, void (Matrix::*method)(int), int number)
{
  std::cout << "Change matrix: " << std::endl;
  history.print();

  std::cout << "Index: ";
  int index;
  std::cin >> index;

  if (index > 0 && index <= history.size())
    (history.get(index - 1).*method)(number);
}