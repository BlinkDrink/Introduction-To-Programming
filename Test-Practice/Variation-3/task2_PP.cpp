#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const long long MAX = 1000000000;

int main()
{
    long long n, newN = 0, tens = 1;
    cin >> n;
    if (n > MAX)
    {
        cout << "Error";
    }

    while (n != 0)
    {
        short currentDigit = n % 10;
        if (currentDigit % 2 == 0)
            newN += tens * (currentDigit / 2);
        else
        {
            newN += tens * (currentDigit);
        }

        n /= 10;
        tens *= 10;
    }

    cout << newN;
}