#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Прочетете от стандартния вход две числа A и B и намерете броя на целите числа в интервала [A, B), такива
че сумата и произведението от цифрите им съвпадат.

Вход:       Изход:
120 125     1
*/
bool sumEqualsProduct(int n)
{
    int sum = 0;
    int product = 1;

    while (n != 0)
    {
        sum += n % 10;
        product *= n % 10;
        n /= 10;
    }

    return sum == product;
}

int main()
{
    int A, B, counter = 0;
    cin >> A >> B;

    for (int i = A; i < B; i++)
    {
        if (sumEqualsProduct(i))
            counter++;
    }

    cout << counter;

    return 0;
}