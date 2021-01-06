#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned short digOccurenceRec(unsigned long long n, unsigned short digit, unsigned short result = 0)
{
    if (n == 0)
    {
        return result;
    }

    return digOccurenceRec(n / 10, 2, result += (n % 10 == digit));
}

int main()
{
    cout << digOccurenceRec(11951, 2); // -> 3
    return 0;
}