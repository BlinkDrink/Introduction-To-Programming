#include <iostream>

using std::cin;
using std::cout;

/*
Напишете програма, която получава две числа x и k и използвайки
побитови операции, умножава числото x по 2^k.

Вход: 5 3

Изход: 40 (5 * 2^3 = 5 * 8 = 40)
*/

int main()
{
    int x, k;
    cin >> x >> k;

    cout << (x << k);

    return 0;
}