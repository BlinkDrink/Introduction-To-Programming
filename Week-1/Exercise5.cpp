#include <iostream>
#include <cmath>

/* Прочетете две цели числа от стандартния вход и разменете техните стойностти:
а) чрез използването на трета променлива.
б) само чрез операциите събиране и изваждане.*/

int main()
{
    // a)
    int a = 10, b = 5;

    int temp = a;
    a = b;
    b = temp;

    std::cout << "a = " << a << " b = " << b << std::endl;

    // б)
    int c = 25, d = 10;

    c = c - d;
    d = d + c;
    c = d - c;

    std::cout << "c = " << c << " d = " << d << std::endl;

    return 0;
}
