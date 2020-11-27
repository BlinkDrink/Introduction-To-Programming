#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която проверява дали въведеното число n е просто и при премахване на последната цифра,
новополученото число също е просто.
*/

bool isPrimeNumber(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    bool isPrime = true;
    cin >> n;

    while (n != 0)
    {
        if (!isPrimeNumber(n))
        {
            isPrime = false;
        }
        n /= 10;
    }

    isPrime ? cout << "TRUE" : cout << "FALSE";

    return 0;
}