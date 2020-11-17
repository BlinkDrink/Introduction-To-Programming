#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
По дадено цяло положително число да се обърне.

Пример:
Вход: 12345
Изход: 54321
*/

int main()
{
    unsigned n;
    cin >> n;

    while (n != 0)
    {
        cout << n % 10;
        n /= 10;
    }

    return 0;
}