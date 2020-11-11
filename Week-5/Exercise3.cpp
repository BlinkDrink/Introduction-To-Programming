#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която по дадено цяло положително число n отпечатва на конзолата първите n реда от следния шаблон:

Вход: 6
Изход:

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
*/
void printNumberTriangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            cout << k << ' ';
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    printNumberTriangle(n);
}