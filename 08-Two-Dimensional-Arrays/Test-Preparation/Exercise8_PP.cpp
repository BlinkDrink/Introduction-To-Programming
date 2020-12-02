#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която приема 2 матрици и ги умножава. Умножението се извършва ред по стълб.
*/
const unsigned MAX_SIZE = 50;

void readArray(int arr[][MAX_SIZE], unsigned n, unsigned m)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    unsigned n, m, i, j;
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int resultArr[MAX_SIZE][MAX_SIZE] = {
        0,
    };

    do
    {
        cin >> n >> m >> i >> j;
    } while (m != i);

    readArray(A, n, m);
    readArray(B, i, j);

    for (unsigned row = 0; row < n; ++row)
    {
        for (unsigned col = 0; col < j; ++col)
        {
            for (unsigned k = 0; k < i; ++k)
            {
                resultArr[row][col] += A[row][k] * B[k][col];
            }
        }
    }

    for (unsigned row = 0; row < n; ++row)
    {
        for (unsigned col = 0; col < j; ++col)
        {
            cout << " " << resultArr[row][col];
        }
        cout << endl;
    }

    return 0;
}