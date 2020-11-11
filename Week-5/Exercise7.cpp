#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която въвежда от клавиатурата цeлите числа m и n (m < n). 
Програмата да извежда броя на числата в интервала [m, n], сумата от цифрите, на които, е просто число.
Използвайте Функцията от предишната задача за проверка.
*/
bool isPrimeNumber(unsigned n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool sumOfDigitsIsPrime(unsigned n)
{
    unsigned sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return isPrimeNumber(sum);
}

int main()
{
    int m, n, sum = 0;
    cin >> m >> n;

    if (m >= n)
        return 1;

    for (int i = m; i <= n; i++)
    {
        if (sumOfDigitsIsPrime(i))
            sum++;
    }

    cout << sum;
}