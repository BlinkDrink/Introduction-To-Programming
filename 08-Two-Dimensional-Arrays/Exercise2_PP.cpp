#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Създайте квадратна матрица и отпечатайте двата диагонала.
Вход:
*/

const int MAX_SIZE = 1005;

int fib(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
    {
        return 1;
    }

    return fib(n - 2) + fib(n - 1);
}

bool isInFibSequence(unsigned el, unsigned fibArr[], unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (el == fibArr[j])
                return true;
        }
    }

    return false;
}

int main()
{
    unsigned n, sum = 0;
    unsigned arr[MAX_SIZE];
    unsigned fibArr[MAX_SIZE];

    do
    {
        cin >> n;
    } while (n < 5 || n > MAX_SIZE);

    for (unsigned i = 0; i < n; i++)
    {
        arr[i] = fib(i);
    }

    for (unsigned i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (isInFibSequence(arr[i], fibArr, n))
        {
            sum += arr[i];
        }
    }

    cout << sum;
}
