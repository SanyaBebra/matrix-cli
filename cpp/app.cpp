#include "../headers/app.h"

void App::run()
{
    show_menu();

    while (running)
    {
        handleMenu();
    }
}

void App::handleMenu()
{
    int option;
    std::cout << "Option: ";
    std::cin >> option;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Oops... Invalid value!" << std::endl;
        return;
    }

    switch (option)
    {
    case 1:
        actionCreateMatrix();
        break;
    case 2:
        actionShowHistory();
        break;
    case 3:
        actionTranspose();
        break;
    case 4:
        actionTakeOutMinus();
        break;
    case 5:
        actionMultiplay();
        break;
    case 6:
        actionSumOrSubstraction();
        break;
    case 0:
        running = false;
        break;
    default:
        std::cout << "Oops... Invalid value!" << std::endl;
        break;
    }
}

void App::actionCreateMatrix()
{
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
}

void App::actionShowHistory() { history.print(); }
void App::actionTranspose() { operation(history, Matrix::transpose); }
void App::actionTakeOutMinus() { operation(history, Matrix::takeOutMinus); }

void App::actionMultiplay()
{
    std::cout << "Number: ";
    int number;
    std::cin >> number;

    operation(history, Matrix::mult, number);
}

void App::actionSumOrSubstraction()
{
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
}