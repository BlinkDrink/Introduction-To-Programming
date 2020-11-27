#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 50;

/*
Създайте квадратна матрица NxN и запишете числото 0 на всички позиции, освен на двата диагонала
Вход:
*/

void readArray(int arr[][MAX_SIZE], int size)
{
    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned j = 0; j < size; j++)
        {
            cin >> arr[i][j];
        }
    }
}
int main()
{
    unsigned N;
    int arr[MAX_SIZE][MAX_SIZE];
    cin >> N;

    readArray(arr, N);

    for (unsigned i = 0; i < N; i++)
    {
        for (unsigned j = 0; j < N; j++)
        {
            if (i != j && j != N - i - 1)
            {
                arr[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}