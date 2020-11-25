#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
По дадено число, да се отпечатат всичките му множители.

Пример:
Вход:
24
Изход:
2 3
*/

int main()
{
    int n;
    cin >> n;

    int multiplier = 2;
    int tmp = 0;

    while (n != 1)
    {
        while (n % multiplier == 0)
        {
            if (tmp == 0)
            {
                cout << multiplier << " ";
                tmp++;
            }
            n /= multiplier;
        }

        multiplier += 1;
        tmp = 0;
    }

    return 0;
}