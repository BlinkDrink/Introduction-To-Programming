#include <iostream>

/*
Напишете програма, която прочита от калвиатурата едно число тип int. Предпоалгаме, че
числото има точно 32 bit-а. В най-старшите 8 бит-а (в най-левите в побитово представяне)
е закодирано 8 битово число, в следващите 8 бит-а друго 8 битово число и т.н. Логично, във
въведеното число има закодирани 4 числа. Изведете ги на конзолата.
*/

using std::cin;
using std::cout;

int main()
{
    const unsigned int BITS_TO_MOVE = 8;
    unsigned int num;
    cin >> num;

    unsigned int mask = 1;
    mask = mask << 1 | 1;
    mask = mask << 1 | 1;
    mask = mask << 1 | 1;
    mask = mask << 1 | 1;
    mask = mask << 1 | 1;
    mask = mask << 1 | 1;
    mask = mask << 1 | 1;
    cout << mask;

    cout << (mask & num) << ' ';

    num >>= BITS_TO_MOVE;
    cout << (mask & num) << ' ';

    num >>= BITS_TO_MOVE;
    cout << (mask & num) << ' ';

    num >>= BITS_TO_MOVE;
    cout << (mask & num) << ' ';

    return 0;
}