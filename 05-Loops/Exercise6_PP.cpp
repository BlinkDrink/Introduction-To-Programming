#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете булева функция, която приема цяло, положително число n и връща 
true ако сумата от цифрите на n е просто число, false в противен случай. Сигнатура на функцията:

bool sumOfDigitsIsPrime(int n)
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
    unsigned n;
    cin >> n;

    sumOfDigitsIsPrime(n) ? cout << "true" : cout << "false";
}