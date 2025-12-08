#include "../headers/history.h"

void History::print()
{
    int number = 1;
    for (Matrix mat : history)
    {
        std::cout << "Index " << number << std::endl;
        mat.print();
        std::cout << "\n\n";

        number++;
    }
}

void History::push(Matrix m) { history.push_back(m); }

Matrix& History::get(int index) {
    return history[index];
}

int History::size() { return history.size(); }