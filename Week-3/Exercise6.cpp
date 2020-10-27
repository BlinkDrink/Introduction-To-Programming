#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Сортирайте три числа използвайки условни конструкции.

Вход:

2 10 -5

Изход:

-5 2 10
*/

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int max = 0;
    int middle = 0;
    int min = 0;

    if (a > b)
    {
        if (a > c)
        {
            max = a;
            middle = c > b ? c : b;
            min = c < b ? c : b;
        }
        else
        {
            max = c;
            middle = a > b ? a : b;
            min = a < b ? a : b;
        }
    }
    else if (b > a)
    {
        if (b > c)
        {
            max = b;
            middle = a > c ? a : c;
            min = a < c ? a : c;
        }
        else
        {
            max = c;
            middle = a > b ? a : b;
            min = a < b ? a : b;
        }
    }

    cout << min << " " << middle << " " << max;

    return 0;
}