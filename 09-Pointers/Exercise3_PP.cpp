#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 100;

unsigned readSize()
{
    unsigned size = 0;
    do
    {
        cin >> size;
    } while (size < 1 || size > MAX_SIZE);
    return size;
}

void printMatrix(int **matrix, unsigned rows, unsigned cols)
{
    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

void readMatrix(int **matrix, unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

int **transposeMatrix(int **matrix, unsigned n, unsigned m)
{
    int **transposed = new int *[m];
    for (unsigned i = 0; i < m; i++)
    {
        transposed[i] = new int[n];
    }

    for (unsigned i = 0; i < m; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            transposed[i][j] = matrix[j][i];
        }
    }

    return transposed;
}

int main()
{
    unsigned n, m;
    n = readSize();
    m = readSize();

    int **matrix = new int *[n];
    int **transposed = new int *[m];

    for (unsigned row = 0; row < n; row++)
    {
        matrix[row] = new int[m];
    }

    readMatrix(matrix, n, m);

    transposed = transposeMatrix(matrix, n, m);

    printMatrix(transposed, m, n);

    for (unsigned i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    for (unsigned i = 0; i < m; i++)
    {
        delete[] transposed[i];
    }

    delete[] transposed;

    return 0;
}
