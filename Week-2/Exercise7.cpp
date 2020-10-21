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
        unsigned int decimal, decimalHex;
        unsigned long long binary = 0, i;

        char hex[50];
        int hexCounter = 0;

        cout << "Enter decimal number:";
        cin >> decimal;

        decimalHex = decimal;
        i = 1;

        // Hexadecimal
        do
        {
            int rem = decimalHex % 16;
            decimalHex /= 16;

            if (rem > 9)
                hex[hexCounter] = (char)(rem - 10 + 'A');
            else
                hex[hexCounter] = (char)(rem + 48);

            hexCounter++;
        } while (decimalHex > 0);

        cout << "The hexadecimal representation is: ";
        for (int i = hexCounter; i >= 0; i--)
        {
            cout << hex[i];
        }

        // Binary
        do
        {
            binary += (decimal % 2) * i;
            i = i * 10;
            decimal = decimal / 2;
        } while (decimal > 0);

        cout << "\nThe binary representation is: " << binary;
    }
}