#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която от число в десетична бройна система въвежда число в двуична.
*/

int main()
{
    {
        unsigned int decimal, decimalHex, temp, hex = 0;
        unsigned long long binary = 0, i;

        cout << "Enter decimal number:";
        cin >> decimal;
        decimalHex = decimal;
        i = 1;
        cout << "The hexadecimal representation is: ";

        // Hexadecimal
        do
        {
            int rem = decimalHex % 16;
            decimalHex /= 16;

            if (rem > 9)
                cout << (char)(rem - 10 + 'A');
            else
                cout << rem;
        } while (decimalHex > 0);

        cout << '\n';

        // Binary
        do
        {
            binary += (decimal % 2) * i;
            i = i * 10;
            decimal = decimal / 2;
        } while (decimal > 0);

        cout << "the binary representation is: " << binary;
    }
}