#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const size_t MAX_SIZE = 100;
/*
Магически квадрат е такава квадратна матрица с размер N, която съдържа като елементи числата от 1
до N2 подредени така, че сумата на елементите във всеки ред, всеки стълб и двата диагонала е една и съща. Вашата
задача е да въведете число N (2 ≤ N ≤ 100), следвано от N
2 цели числа. Проверете дали те представляват магически
квадрат.


Вход:       Изход:      Вход:       Изход:
3            Yes           2           No
2 7 6                    1 3
9 5 1                    2 4
4 3 8

*/

size_t readSize()
{
    size_t N;
    do
    {
        cout << "N=";
        cin >> N;
    } while (N < 2 || N > 100);

    return N;
}

void read2DArray(int arr[][MAX_SIZE], size_t N)
{
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            cin >> arr[i][j];
}

bool IsNotRepeating(int arr[], int n)
{
    for (int i = 0; i < n * n; i++)
    {
        for (int j = i + 1; j < n * n; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool IsContaining(int arr[], int helpArr[], int n)
{
    for (int i = 0; i < n * n; i++)
    {
        bool contains = false;
        for (int j = 0; j < n * n; j++)
        {
            if (arr[i] == helpArr[j])
            {
                contains = true;
                break;
            }
        }
        if (!contains)
        {
            return false;
        }
    }
    return true;
}

bool isMagicSquare(int arr[][MAX_SIZE], size_t N, int sum)
{
    int mainDiagSum = 0;
    int secondaryDiagSum = 0;
    int straightArr[MAX_SIZE];
    int straightArrIndex = 0;
    int helperArr[MAX_SIZE];
    int helpArrIndex = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            helperArr[helpArrIndex++] = helpArrIndex;
            straightArr[straightArrIndex++] = arr[i][j];
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        int rowSum = 0;

        for (size_t j = 0; j < N; j++)
        {
            rowSum += arr[i][j];
        }

        if (rowSum != sum)
            return false;
    }

    for (size_t i = 0; i < N; i++)
    {
        int colSum = 0;

        for (size_t j = 0; j < N; j++)
        {
            colSum += arr[j][i];
        }

        if (colSum != sum)
            return false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            // Condition for principal diagonal
            if (i == j)
                mainDiagSum += arr[i][j];

            // Condition for secondary diagonal
            if ((i + j) == (N - 1))
                secondaryDiagSum += arr[i][j];
        }
    }

    if (mainDiagSum != sum || secondaryDiagSum != sum || (!IsNotRepeating(straightArr, N) || !IsContaining(straightArr, helperArr, N)))
        return false;

    return true;
}

int main()
{
    size_t N;
    int matrix[MAX_SIZE][MAX_SIZE];
    int sum = 0;

    N = readSize();
    read2DArray(matrix, N);

    // get the sum of the first row so I can have a single source of truth
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            sum += matrix[i][j];
        }

        break;
    }

    isMagicSquare(matrix, N, sum) ? cout << "Yes" : cout << "No";

    return 0;
}