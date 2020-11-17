#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише функция която по дадено n пресмята n!. n! = n*(n - 1)*(n - 2)*...*3*2*1.
Сигнатура на функцията:

long long fact(int n)
*/
long long fact(int n)
{
    long long factoriel = 1;

    for (int i = 1; i <= n; i++)
    {
        factoriel *= i;
    }

    return factoriel;
}

int main()
{
    int n;
    cin >> n;

    if (n < 0)
        return 1;

    cout << fact(n);
}