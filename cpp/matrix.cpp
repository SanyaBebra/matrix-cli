#include "../headers/matrix.h"

// Конструктор
Matrix::Matrix(int size_n, int size_m) : rows(size_n), cols(size_m), matrix(rows, std::vector<int>(cols)) {}

// Методы
void Matrix::print()
{
    for (std::vector<int> row : matrix)
    {
        for (int col : row)
            std::cout << col << "\t";
        std::cout << "\n\n";
    }
}

bool Matrix::set(int elem, int row, int col) // !!!
{
    if (!(row >= rows || col >= cols))
    {
        matrix[row][col] = elem;
        return true;
    }

    return false;
}

void Matrix::transpose()
{
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transposed[j][i] = matrix[i][j];

    matrix = transposed;

    std::swap(rows, cols);
}

void Matrix::takeOutMinus()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] *= -1;
}

void Matrix::mult(int number)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] *= number;
}

int Matrix::getRows() { return rows; }
int Matrix::getCols() { return cols; }