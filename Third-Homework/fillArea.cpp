#include <iostream>

using std::abs;
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;

typedef unsigned char pixel[3];

pixel **fillArea(
    const pixel *const *const image,
    size_t width, size_t height,
    size_t row, size_t column);

void readMatrix(unsigned char **matrix, size_t rows, size_t columns)
{
    unsigned tmp;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            cin >> tmp;
            matrix[i][j] = (int)tmp;
            unsigned char test = (unsigned)matrix[i][j];

            if (!cin)
            {
                cout << "Invalid number";
                matrix = nullptr;
                return;
            }
        }
    }
}

void printImage(const pixel *const *const matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            if ((unsigned)matrix[i][j][0] < 10)
            {
                cout << " " << (unsigned)matrix[i][j][0] << " ";
            }
            else
            {
                cout << (unsigned)matrix[i][j][0] << " ";
            }
        }
        cout << "\n";
    }
}

void clearMatrixByRows(unsigned char **matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void clearImageByRows(const pixel *const *const image, unsigned rows, unsigned cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] image[i];
    }
    delete[] image;
}

unsigned char **matrixAllocation(size_t rows, size_t columns)
{
    unsigned char **matrix = new (nothrow) unsigned char *[rows];
    if (!matrix)
        return matrix;

    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new unsigned char[columns];
        if (!matrix[i])
        {
            clearMatrixByRows(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

pixel **createImage(unsigned char **matrix, unsigned rows, unsigned cols)
{
    pixel **image = new pixel *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        image[i] = new pixel[cols];
    }

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                image[i][j][k] = matrix[i][j];
            }
        }
    }

    return image;
}

bool fillAreaRec(pixel **modified, const pixel *const *const image,
                 size_t width, size_t height,
                 size_t row, size_t column, size_t lastRow, size_t lastCol)
{
    if (row >= height || column >= width)
    {
        return false;
    }
    if (modified[row][column][0] == 0)
    {
        return false;
    }

    unsigned fst = (unsigned)image[lastRow][lastCol][0];
    unsigned snd = (unsigned)image[row][column][0];

    unsigned max = std::max(fst, snd);
    unsigned min = std::min(fst, snd);

    if (max - min > 1)
    {
        return false;
    }

    modified[row][column][0] = 0;
    modified[row][column][1] = 0;
    modified[row][column][2] = 0;

    return fillAreaRec(modified, image, width, height, row + 1, column, row, column) ||
           fillAreaRec(modified, image, width, height, row - 1, column, row, column) ||
           fillAreaRec(modified, image, width, height, row, column + 1, row, column) ||
           fillAreaRec(modified, image, width, height, row, column - 1, row, column);
}

int main()
{
    unsigned rows, cols, targetRow, targetCol;
    cin >> rows >> cols >> targetRow >> targetCol;
    if (!cin || targetRow >= rows || targetCol >= cols)
    {
        cout << "Invalid input!";
        return 1;
    }

    unsigned char **matrix = nullptr;
    matrix = matrixAllocation(rows, cols);

    if (!matrix)
    {
        return 1;
    }

    readMatrix(matrix, rows, cols);
    const pixel *const *const image = createImage(matrix, rows, cols);

    pixel **modifiedImage = fillArea(image, cols, rows, targetRow, targetCol);
    printImage(modifiedImage, rows, cols);

    clearMatrixByRows(matrix, rows);
    clearImageByRows(image, rows, cols);
    clearImageByRows(modifiedImage, rows, cols);
    return 0;
}

pixel **fillArea(const pixel *const *const image,
                 size_t width, size_t height,
                 size_t row, size_t column)
{
    pixel **modifiedImage = new pixel *[height];
    for (size_t i = 0; i < height; i++)
    {
        modifiedImage[i] = new pixel[width];
        if (!modifiedImage[i])
        {
            clearImageByRows(modifiedImage, i, width);
            return nullptr;
        }
    }

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            for (size_t k = 0; k < 3; k++)
            {
                modifiedImage[i][j][k] = (unsigned char)image[i][j][k];
            }
        }
    }

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            if (i == row && j == column)
            {
                fillAreaRec(modifiedImage, image, width, height, row, column, row, column);
            }
        }
    }

    return modifiedImage;
}