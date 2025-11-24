#include <iostream>
#include <cstdlib>
#include <vector>
#include "headers/functions.h"
#include "headers/matrix.h"
#include "headers/history.h"

int main()
{
  History history;

  show_header(1.4);
  show_menu();

  int option = 0;
  std::cout << "Option: ";
  while (std::cin >> option)
  {
    if (option == 1)
    {
      int n, m;
      std::cout << "Size 'n': ";
      std::cin >> n;
      std::cout << "Size 'm': ";
      std::cin >> m;

      Matrix matrix = create_matrix(n, m);
      history.push(matrix);

      matrix.print();
    }
    else if (option == 2)
    {
      history.print();
    }
    else if (option == 3)
    {
      std::cout << "Change matrix: " << std::endl;
      history.print();

      std::cout << "> ";
      int number;
      std::cin >> number;

      history.transpose(number - 1);
    }

    std::cout << "Option: ";
  }

  system("pause");
  return 0;
}