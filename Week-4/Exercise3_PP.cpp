#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която прочита цяло положително число и проверява дали то е просто или не.

Вход:
17
Изход:
"YES"
*/

int main()
{
    unsigned n;
    cin >> n;

    bool isPrime = true;

    for (unsigned i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    cout << (isPrime ? "YES" : "NO");

    return 0;
}