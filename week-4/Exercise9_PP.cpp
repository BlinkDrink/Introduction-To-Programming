#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
По въведени n (нечетно) на брой числа, всяко от които се среща по два пъти с изключение на едно,
коeто е уникално. Намерете това число. При решаване на задачата не е позволено използването на масиви.
Входът за програмата ви ще изглежда по следния начин:
На първия ред едно число n - броя числа
На втория ред n на брой цели положителни числа.

При реализацията на програмата допускаме че потребителят винаги ще въвежда коректни входни данни.

Пример:
Вход:
5
1 2 3 2 1
Изход:
3
*/

int main()
{
    unsigned n, sum = 0;
    cin >> n;

    unsigned long gluedDigits = 0, copyGluedDigits;
    unsigned i = 0;

    while (i < n)
    {
        unsigned num;
        cin >> num;

        sum += num;

        gluedDigits = (gluedDigits * 10) + num;

        i++;
    }

    for (int k = 0; k < n; k++)
    {
        unsigned currentDigit = gluedDigits % 10;
        gluedDigits /= 10;
        copyGluedDigits = gluedDigits;

        while (copyGluedDigits != 0)
        {
            if (currentDigit == (copyGluedDigits % 10))
            {
                sum -= (2 * currentDigit);
            }

            copyGluedDigits /= 10;
        }

        copyGluedDigits = gluedDigits;
    }

    cout << sum;

    return 0;
}