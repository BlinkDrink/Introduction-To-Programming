#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която въвежда цяло число n (1 ≤ n ≤ 10) и печата спирала с размер n, като в следните примери:

ВХОД: 4

ИЗХОД:
1  2 3  4
12 13 14 5
11 16 15 6
10 9  8  7
*/

const int MAX_SIZE = 50;

int main()
{
    int n, length, k = 1, p = 0, i;
    cin >> n;
    int ARR[50][50];
    length = n;

    while (k <= n * n)
    {
        for (i = p; i < length; i++)
        {
            ARR[p][i] = k++;
        }
        for (i = p + 1; i < length; i++)
        {
            ARR[i][length - 1] = k++;
        }
        for (i = length - 2; i >= p; i--)
        {
            ARR[length - 1][i] = k++;
        }
        for (i = length - 2; i > p; i--)
        {
            ARR[i][p] = k++;
        }
        p++, length = length - 1;
    }
    if (!n % 2)
    {
        ARR[(n + 1) / 2][(n + 1) / 2] = n * n;
    }
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ARR[i][j] << " ";
        }
        cout << endl;
    }
}