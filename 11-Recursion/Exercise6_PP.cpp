#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned short chocolateEatingRec(double money, double price, double wrap)
{
    if (money - price < 0)
    {
        return 0;
    }

    return 1 + chocolateEatingRec(money - price + wrap, price, wrap);
}

int main()
{
    double money, price, wrap;
    cin >> money >> price >> wrap;
    cout << chocolateEatingRec(money, price, wrap);
    return 0;
}