#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
При зададени координати на два шахматни офицера, стоящи на n-ти ред и на m-та колона,
проветере дали се "бият"

Вход: Въвеждат 4 числа: n1, m1, n2 и m2.

Изход: Да се изведе YES, ако се "бият" и NO в противен случай.

Примери

Вход: 1 1 5 5

Изход: YES

Вход: 3 2 2 2

Изход: NO
*/

int main()
{
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;

    bool theyFight = false;

    int m1Temp = m1;

    for (int i = n1; i <= 8; i++)
    {
        if ((i == n2) && (m1Temp == m2))
        {
            theyFight = true;
            break;
        }

        m1Temp++;
    }

    m1Temp = m1;

    for (int i = n1; i >= 1; i--)
    {
        if ((i == n2) && (m1Temp == m2))
        {
            theyFight = true;
            break;
        }

        m1Temp--;
    }

    m1Temp = m1;

    for (int i = n1; i >= 1; i--)
    {
        if ((i == n2) && (m1Temp == m2))
        {
            theyFight = true;
            break;
        }

        m1Temp++;
    }

    m1Temp = m1;

    for (int i = n1; i <= 8; i++)
    {
        if ((i == n2) && (m1Temp == m2))
        {
            theyFight = true;
            break;
        }

        m1Temp--;
    }

    theyFight ? cout << "YES" : cout << "NO";

    return 0;
}