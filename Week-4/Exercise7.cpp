#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която прочита едно цяло положително число и извежда на 
конзолата двоичния му запис в правилния ред. Забранено е използването на масиви. 
(Подсказка: намерете най-старшия бит на числото)
*/

int main()
{
    unsigned n;
    cin >> n;

    unsigned nBinary = 0;
    unsigned nBinaryReversed = 0;

    while (n != 0)
    {
        unsigned currentDigit = n % 2;
        nBinary = (nBinary * 10) + currentDigit;
        n /= 2;
    }

    while (nBinary != 0)
    {
        cout << nBinary % 10;
        nBinary /= 10;
    }

    return 0;
}