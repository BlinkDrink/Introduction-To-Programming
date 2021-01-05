#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned fib(unsigned n, unsigned f1, unsigned f2, unsigned result = 0)
{
    if (n == 1)
    {
        return result;
    }

    return fib(n - 1, f2, f2 + f1, f1 + f2);
}

unsigned fibWrapper(unsigned n)
{
    return fib(n, 0, 1);
}

int main()
{
    cout << fibWrapper(5);
    return 0;
}