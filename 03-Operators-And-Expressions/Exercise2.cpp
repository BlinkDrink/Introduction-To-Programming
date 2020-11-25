#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която прочита от клавиатурата едно число тип int. 
Предполагаме, че числото има точно 32 bit-a. В най-старшите 8 бит-а 
(най-левите в побитовото представяне) е закодирано 8 битово число, в
следващите 8 бит-а друго 8 битово число и тн. Логично, във въведеното 
число има закодирани 4 числа. Изведете ги на конзолата.

Вход: 2729336101

Изход: 162 174 93 37
*/

int main()
{
    const unsigned int BITS_TO_MOVE = 8;
    unsigned int num;
    cin >> num;

    unsigned int mask = 255; // 1111 1111 in bits

    for (int i = 0; i < 4; i++)
    {
        cout << (num & mask) << " ";
        num >>= BITS_TO_MOVE;
    }

    return 0;
}