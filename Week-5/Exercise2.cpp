#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която въвежда цяло положително число n и печата ромбче от звездички с размер n.
Пример:
Вход: 1
Изход: *

Вход: 3
Изход:

  *  
 * * 
* * *
 * * 
  *  
*/
void printRhombus(int n)
{
    int spacing = 1;

    for (int row = 1; row <= n; row++)
    {
        for (int i = 0; i < n - row; ++i)
        {
            cout << ' ';
        }

        for (int k = 0; k < row; k++)
        {
            cout << '*';
            cout << ' ';
        }

        cout << endl;
    }

    for (int row = n - 1; row > 0; row--)
    {
        for (int i = 0; i < n - row; ++i)
        {
            cout << ' ';
        }

        for (int k = 0; k < row; k++)
        {
            cout << '*';
            cout << ' ';
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    printRhombus(n);
}