#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool cmpDigitsRec(unsigned long long n, bool result = true)
{
    if (n == 0 || result == false)
    {
        return result;
    }

    return cmpDigitsRec(n / 10, n % 10 < (n / 10) % 10);
}

bool cmpDigitsWrapper(unsigned long long n)
{
    return cmpDigitsRec(n);
}

int main()
{
    cout << cmpDigitsWrapper(1);
    return 0;
}