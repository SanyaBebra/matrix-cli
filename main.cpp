#include <iostream>
#include <cstdlib>
#include <vector>
#include "headers/history.h"
#include "headers/functions.h"
#include "headers/matrix.h"

int main()
{
  History history;

  show_menu();

  int option;
  bool running = true;
  while (running)
  {
    std::cout << "Option: ";
    std::cin >> option;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(32767, '\n');
      std::cout << "Oops... Invalid value!" << std::endl;
      continue;
    }

    switch (option)
    {
    case 1:
      int rows, cols;
      std::cout << "Rows: ";
      std::cin >> rows;
      std::cout << "Columns: ";
      std::cin >> cols;

      if (rows > 0 && cols > 0)
      {
        Matrix matrix = create_matrix(rows, cols);
        history.push(matrix);
      }

      break;
    case 2:
      history.print();
      break;
    case 3:
      operation(history, Matrix::transpose);
      break;
    case 4:
      operation(history, Matrix::takeOutMinus);
      break;
    case 5:
      std::cout << "Number: ";
      int number;
      std::cin >> number;

      operation(history, Matrix::mult, number);
      break;
    case 6:
      std::cout << "Index Op Index: ";
      int index_1, index_2;
      char op;
      std::cin >> index_1 >> op >> index_2;

      if (op == '+')
        operation(history, Matrix::sum, index_1, index_2);
      else if (op == '-')
        operation(history, Matrix::subtraction, index_1, index_2);
      else
        std::cout << "Oops... Invalid operation!" << std::endl;

      break;
    case 0:
      running = false;
      break;
    default:
      std::cout << "Oops... Invalid value!" << std::endl;
      break;
    }
  }

  system("pause");
  return 0;
}