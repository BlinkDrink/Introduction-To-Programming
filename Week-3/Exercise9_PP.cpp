#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма приемаща последователност от 32-битово число и четири 8-битови(k, l, m, n).
Програмата трябва да провери дали на позиция съответстваща (k, l, m, n) бит има "1" и ако е
изпълнено отпечатва произведението от позициите, удовлетворяващи условието. В противен случай,
ако всички позиции сочат бит със стойност "0", отпечатайте средното аритметично.

Вход: 166 1 2 3 4

Изход: 6

Пояснение 166 -> 10100110, само 2-ри и 3-ти бит имат стойност "1"
*/

bool isBitZeroOrOne(int num, int mask, int shifter)
{
    return ((num & (mask << shifter)) != 0);
}

int main()
{
    int num, k, l, m, n;
    cin >> num >> k >> l >> m >> n;

    int zeroesCount = 0;
    int product = 1;
    unsigned mask = 1;

    isBitZeroOrOne(num, mask, k - 1) ? product *= k : zeroesCount++;
    isBitZeroOrOne(num, mask, l - 1) ? product *= l : zeroesCount++;
    isBitZeroOrOne(num, mask, m - 1) ? product *= m : zeroesCount++;
    isBitZeroOrOne(num, mask, n - 1) ? product *= n : zeroesCount++;

    if (zeroesCount != 4)
    {
        cout << product;
    }
    else
    {
        cout << (k + l + m + n) / 4.0;
    }

    return 0;
}