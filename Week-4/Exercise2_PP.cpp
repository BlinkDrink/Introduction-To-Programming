#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се провери дали дадено число е палиндром. Палиндромът число,
което се чете по един и същ начин от ляво надясно и от дясно наляво.

Примери:
Вход: 12321
Изход: YES
Вход: 12345
Изход: NO
*/

int main()
{
    unsigned n;
    cin >> n;

    unsigned tmp = n;
    unsigned reversed = 0;

    while (tmp != 0)
    {
        unsigned currentDigit = tmp % 10;
        reversed = (reversed * 10) + currentDigit;
        tmp /= 10;
    }

    cout << (reversed == n ? "YES" : "NO");

    return 0;
}