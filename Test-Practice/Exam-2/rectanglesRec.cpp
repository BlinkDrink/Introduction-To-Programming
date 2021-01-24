#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned getSize()
{
    unsigned n;
    const unsigned MAX_INPUT = 100;
    do
    {
        cin >> n;
    } while (!cin || n < 1 || n > MAX_INPUT);
    return n;
}

void readMatrix(unsigned **matrix, unsigned rows, unsigned cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void clearMatrixByRows(unsigned **matrix, unsigned rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

unsigned **matrixAllocation(unsigned rows, unsigned cols)
{
    unsigned **matrix = new (std::nothrow) unsigned *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new unsigned[cols];
        if (!matrix[i])
        {
            clearMatrixByRows(matrix, i);
            return matrix;
        }
        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

bool canFindSpotForRect(unsigned **table, unsigned tableSize, unsigned rectHeight, unsigned rectWidth)
{
    bool canFit = true;

    if (tableSize < rectHeight || tableSize < rectWidth)
    {
        return false;
    }

    for (size_t i = 0; i < tableSize; i++)
    {
        for (size_t j = 0; j < tableSize; j++)
        {
            for (size_t l = 0; l < rectHeight; l++)
            {
                for (size_t k = 0; k < rectWidth; k++)
                {
                    if (table[l][k] != 0)
                    {
                        canFit = false;
                    }
                }
            }

            if (canFit)
            {
                for (size_t l = 0; l < rectHeight; l++)
                {
                    for (size_t k = 0; k < rectWidth; k++)
                    {
                        table[l][k] = 1;
                    }
                }
                return canFit;
            }
        }
    }
    return canFit;
}

bool canFillTableRec(int n, unsigned tableSize, unsigned rectCount, unsigned **rectangles, unsigned **table, unsigned rectRows, unsigned currentRect)
{
    if (currentRect > rectRows || rectCount > rectRows)
    {
        return false;
    }
    if (n < 0)
    {
        return false;
    }
    if (n == 0 && rectCount == 0)
    {
        return true;
    }
    if (!canFindSpotForRect(table, tableSize, rectangles[currentRect][0], rectangles[currentRect][1]))
    {
        return false;
    }

    unsigned rectArea = rectangles[currentRect][0] * rectangles[currentRect][1];

    return canFillTableRec(n - rectArea, tableSize, rectCount - 1, rectangles, table, rectRows, currentRect + 1) ||
           canFillTableRec(n - rectArea, tableSize, rectCount - 1, rectangles, table, rectRows, currentRect - 1);
}

int main()
{
    unsigned n = getSize();
    unsigned rectCount = getSize();
    unsigned **table = matrixAllocation(n, n);
    unsigned **rectangles = matrixAllocation(rectCount, 2);
    if (!rectangles || !table)
    {
        return 1;
    }
    readMatrix(rectangles, rectCount, 2);

    cout << canFillTableRec(n * n, n, rectCount, rectangles, table, rectCount, 0);

    clearMatrixByRows(rectangles, rectCount);
    clearMatrixByRows(table, n);
    return 0;
}