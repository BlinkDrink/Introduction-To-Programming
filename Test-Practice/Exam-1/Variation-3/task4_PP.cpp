#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 200;

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

int main()
{
    int N, mainDiagSum = 0, secondDiagSum = 0;
    cin >> N;
    int arr[MAX_SIZE][MAX_SIZE];

    int helperArr[MAX_SIZE * MAX_SIZE];
    int straightArr[MAX_SIZE * MAX_SIZE];
    int indexStr8 = 0;

    int ind = 1;
    for (int i = 0; i < N * N; i++)
    {
        helperArr[i] = ind++;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            straightArr[indexStr8++] = arr[i][j];
        }
    }

    bool isMagicSquare = true;

    if (!IsNotRepeating(straightArr, N) || !IsContaining(straightArr, helperArr, N))
    {
        isMagicSquare = false;
    }

    for (int i = 0; i < N; i++)
    {
        mainDiagSum += arr[i][i];
        secondDiagSum += arr[i][N - 1 - i];
    }

    if (secondDiagSum != mainDiagSum)
    {
        isMagicSquare = false;
    }

    for (int i = 0; i < N; i++)
    {
        int rowSum = 0;
        int colSum = 0;

        for (int j = 0; j < N; j++)
        {
            rowSum += arr[i][j];
            colSum += arr[j][i];
        }

        if (rowSum != mainDiagSum || colSum != mainDiagSum)
        {
            isMagicSquare = false;
        }
    }

    cout << (isMagicSquare ? "Yes" : "No");

    return 0;
}