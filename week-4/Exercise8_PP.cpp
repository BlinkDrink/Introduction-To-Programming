#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която прочита цяло положително число и го представя
като сума от степени на двойката. (Пример: 19 = 1 + 2 + 16)
*/

int main()
{
    unsigned n;
    cin >> n;

    unsigned tmp = n;
    unsigned mask = 1;
    unsigned digitsCount = 0;

    while (tmp != 0)
    {
        tmp /= 2;
        digitsCount++;
    }

    cout << n << " = ";
    for (int i = 0; i < digitsCount; i++)
    {
        unsigned powOf2AtDigit = n & (mask << i);
        if (powOf2AtDigit != 0)
            cout << powOf2AtDigit << " + ";
    }

    return 0;
}