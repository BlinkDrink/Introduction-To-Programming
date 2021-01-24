#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 10 * 10;
/*
При главоблъсканицата „Судоку“ задачата е да се разположат числа в клетките на квадратна матрица с
размери N
2
x N2
, така че във всеки ред, всеки стълб и всяко под-квадратче с размери N x N да бъдат записани
числата от 1 до N
2
. Вашата задача е да прочетете числата в такъв квадрат и да проверите дали е валидно решение
на такава главоблъсканица.
Пример:
Вход:   Изход:         Вход:       Изход:
2       Yes               2           No
1 2 3 4             1 2 3 4
3 4 1 2             2 1 3 4
2 3 4 1             1 2 3 4
4 1 2 3             4 1 2 3

*/
size_t readSize()
{
    size_t N;
    do
    {
        cout << "N=";
        cin >> N;
    } while (N < 1 || N > MAX_SIZE);

    return N;
}

void read2DArray(int arr[][MAX_SIZE], size_t size)
{
    for (size_t i = 0; i < size; i++)
        for (size_t j = 0; j < size; j++)
            cin >> arr[i][j];
}

bool isValid(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        int element = arr[i];
        for (size_t j = 0; j < size; j++)
        {
            if (element == arr[j] && i != j)
                return false;
        }
    }

    return true;
}

bool isValidSubSquare(int arr[][MAX_SIZE], size_t size)
{
    for (size_t row = position; row < size; row++)
    {
        for (size_t col = position; col < size; col++)
        {
            int element = arr[row][col];
            for (size_t r = 0; r < size; r++)
            {
                for (size_t c = 0; c < size; c++)
                {
                    if (element == arr[r][c] && r != row && c != col)
                        return false;
                }
            }
        }
    }
    return true;
}

bool isSudoku(int arr[][MAX_SIZE], size_t size, int N)
{
    int rows[MAX_SIZE];
    int cols[MAX_SIZE];
    int squares[MAX_SIZE][MAX_SIZE];

    int counter = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            rows[j] = arr[i][j];

        if (!isValid(rows, size))
            return false;
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            cols[j] = arr[j][i];

        if (!isValid(cols, size))
            return false;
    }

    for (size_t row = 0; row < size; row += N)
    {
        for (size_t col = 0; col < size; col += N)
        {
            for (int r = row; r < row + N; r++)
            {
                for (int c = col; c < col + N; c++)
                    squares[r][c] = arr[r][c];
            }
            if (!isValidSubSquare(squares, N))
                return false;
        }
    }

    return true;
}

int main()
{
    size_t N;
    int arr[MAX_SIZE][MAX_SIZE];
    N = readSize();
    read2DArray(arr, N * N);

    isSudoku(arr, N * N, N) ? cout << "Yes" : cout << "No";

    return 0;
}