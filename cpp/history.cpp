#include "../headers/history.h"

void History::print()
{
    int number = 1;
    for (Matrix mat : history)
    {
        std::cout << "Number " << number << std::endl;
        mat.print();
        std::cout << "\n\n";

        number++;
    }
}

void History::push(Matrix m) { history.push_back(m); }

void History::transpose(int index) { history[index].transpose(); }

int History::size() { return history.size(); }