#include <iostream>
#include <cstdlib>
#include <vector>
#include "headers/functions.h"
#include "headers/matrix.h"
#include "headers/history.h"

int main()
{
  History history;

  show_header(1.3);
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

      Matrix matrix(n, m);

      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
          int elem;
          std::cout << "A[" << i << "][" << j << "] = ";
          std::cin >> elem;

          matrix.set(elem, i, j);
        }

      history.push(matrix);

      matrix.print();
    }
    else if (option == 2)
    {
      history.print();
    }

    std::cout << "Option: ";
  }

  system("pause");
  return 0;
}