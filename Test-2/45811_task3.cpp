#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
using std::swap;

//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Използван компилатор: mingw-64
//

void clearMatrixByRows(int **matrix, unsigned row)
{
    for (size_t i = 0; i < row; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void readMatrix(int **matrix, unsigned rows, unsigned cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

int **allocateMatrix(unsigned rows, unsigned cols)
{
    int **matrix = new (nothrow) int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new (nothrow) int[cols];
        if (!matrix)
        {
            clearMatrixByRows(matrix, i);
            return nullptr;
        }
    }
    return matrix;
}

unsigned getRowLengthDivisibleByK(int *arr, unsigned size, int k)
{
    unsigned count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % k == 0)
        {
            count++;
        }
    }
    return count;
}

void inputModifiedRow(int *modified, unsigned modifiedLen, int *source, unsigned sourceLen, int k)
{
    unsigned modifInd = 0;
    for (size_t i = 0; i < sourceLen; i++)
    {
        if (modifInd >= modifiedLen)
        {
            break;
        }

        if (source[i] % k == 0)
        {
            modified[modifInd] = source[i];
            modifInd++;
        }
    }
}

int **modifyMatrix(int **matrix, unsigned rows, unsigned cols, int k)
{
    int **modified = new (nothrow) int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        unsigned newRowLength = getRowLengthDivisibleByK(matrix[i], cols, k);
        modified[i] = new int[newRowLength];

        inputModifiedRow(modified[i], newRowLength, matrix[i], cols, k);

        for (size_t j = 0; j < newRowLength; j++)
        {
            cout << modified[i][j] << " ";
        }
        cout << endl;
    }

    return modified;
}

int main()
{
    int **matrix = nullptr;
    unsigned rows, cols;
    cin >> rows >> cols;
    matrix = allocateMatrix(rows, cols);
    if (!matrix)
    {
        return 1;
    }

    readMatrix(matrix, rows, cols);
    int K;
    cin >> K;

    int **modified = modifyMatrix(matrix, rows, cols, K);

    clearMatrixByRows(matrix, rows);
    clearMatrixByRows(modified, rows);
    return 0;
}
