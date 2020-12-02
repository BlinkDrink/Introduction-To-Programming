#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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

unsigned exerciseCondition(int arr[][MAX_SIZE], unsigned n, unsigned m)
{
    unsigned elements = 0;

    for (unsigned i = 1; i < n; i++)
    {
        for (unsigned j = 1; j < m; j++)
        {
            if ((arr[i - 1][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j - 1] <= arr[i][j]) &&
                (arr[i - 1][j + 1] + arr[i + 1][j] + arr[i - 1][j + 1] + arr[i - 1][j - 1] <= arr[i][j]))
            {
                elements++;
            }
        }
    }

    return elements;
}

int main()
{
    unsigned n, m;
    int arr[MAX_SIZE][MAX_SIZE];
    cin >> n >> m;

    readArray(arr, n, m);
    unsigned elements = exerciseCondition(arr, n, m);

    cout << elements;

    return 0;
}
