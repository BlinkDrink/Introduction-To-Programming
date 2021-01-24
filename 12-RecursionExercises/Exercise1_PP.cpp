#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
1.Напишете програма, която симулира изпълнението на n вложени цикъла от 1 до n. Пример:
2   1 1
    1 2
    2 1
    2 2
*/
void loop1(int i, int j, unsigned n)
{
    if (j > n)
    {
        return;
    }

    cout << i << " " << j << endl;

    loop1(i, j + 1, n);
}

void loop2(int i, unsigned n)
{
    if (i > n)
    {
        return;
    }

    loop1(i, 1, n);
    loop2(i + 1, n);
}

int main()
{
    unsigned n;
    cin >> n;
    loop2(1, n);
    return 0;
}