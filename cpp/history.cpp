#include "../headers/history.h"

void History::print()
{
    int index = 1;
    for (Matrix mat : history)
    {
        std::cout << "Matrix number " << index << std::endl;
        mat.print();
        std::cout << "\n\n";

        index++;
    }
}

void History::push(Matrix m) { history.push_back(m); }

void History::transpose(int index)
{
    history[index].transpose();
}