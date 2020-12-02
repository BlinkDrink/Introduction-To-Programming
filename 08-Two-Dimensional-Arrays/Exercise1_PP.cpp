#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Създайте квадратна матрица и отпечатайте двата диагонала.
Вход:
*/

int main()
{
    long long n;
    int arr[10] = {
        0,
    };

    cin >> n;
    while (n != 0)
    {
        int tmp = n % 10;
        arr[tmp]++;
        n /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << i << " - " << arr[i] << endl;
    }
}