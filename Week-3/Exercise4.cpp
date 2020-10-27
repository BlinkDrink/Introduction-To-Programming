#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Имаме шоколад с размер n x m квадратни блокчета. 
Интересува ни дали можем да отчупим от шоколада k блокчета с едно разчупване по права линия.
По въведени n, m и k определете дали това може да се случи.

Примери

Вход: 3 2 4

Изход: YES

Вход: 3 2 1

Изход: NO
*/

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    bool isPossible = false;

    if (k == 1 && (n == 1 || m == 1))
    {
        cout << "YES";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int area = i * m;

            if ((area % k == 0) && (area / k == 1))
                isPossible = true;
        }

        for (int i = 1; i <= m; i++)
        {
            int area = i * n;

            if ((area % k == 0) && (area / k == 1))
                isPossible = true;
        }

        isPossible ? cout << "YES" : cout << "NO";
    }

    return 0;
}