#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която въвежда цяло положително число n и печата правоъгълен триъгълник от звездички с размер n.
Пример:
Вход: 1
Изход: *

Вход: 3
Изход:

*
* *
* * *

*/
void printTriangle(int n)
{
    for (int row = 0; row <= n; row++)
    {
        for (int k = 0; k < row; k++)
        {
            cout << '*';
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    printTriangle(n);
}