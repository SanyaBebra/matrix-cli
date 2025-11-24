#include <iostream>
#include <cstdlib>
#include <vector>
#include "headers/functions.h"
#include "headers/matrix.h"
#include "headers/history.h"

int main()
{
  History history;

  show_header(1.5);
  show_menu();

  int option = 0;
  std::cout << "Option: ";
  while (true)
  {
    std::cin >> option;

    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(32767, '\n');
      std::cout << "Oops... Invalid value!" << std::endl;
    }

    switch (option)
    {
    case 1:
      int n, m;
      std::cout << "Size 'n': ";
      std::cin >> n;
      std::cout << "Size 'm': ";
      std::cin >> m;

      if (n > 0 && m > 0)
      {
        Matrix matrix = create_matrix(n, m);
        history.push(matrix);

        matrix.print();
      }

      break;
    case 2:
      history.print();
      break;
    case 3:
      std::cout << "Change matrix: " << std::endl;
      history.print();

      std::cout << "Number: ";
      int number;
      std::cin >> number;

      if (number > 0 && number <= history.size())
        history.transpose(number - 1);

      break;
    }

    std::cout << "Option: ";
  }

  system("pause");
  return 0;
}