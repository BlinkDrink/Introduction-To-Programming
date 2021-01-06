#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned long long fibRec(unsigned n, unsigned long long f1, unsigned long long f2)
{
    if (n == 0)
    {
        return f2;
    }

    return fibRec(n - 1, f2, f1 + f2);
}

unsigned long long fibWrapper(unsigned n)
{
    return fibRec(n, 0, 1);
}

int main()
{
    cout << fibWrapper(5);
    return 0;
}