#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
2. Напишете рекурсивна програма, която генерира и отпечатва всички комбинации с повторение 
на k елемента над n-елементно множество. Измислете и реализирайте итеративен алгоритъм за
 същата задача.
n=3, k = 2
(1 1), (1 2), (1 3), (2 2), (2 3), (3 3)
*/
void loop1(int i, int j, unsigned k)
{
    if (j > k)
    {
        return;
    }

    cout << i << " " << j << endl;

    loop1(i, j + 1, k);
}

void loop2(int i, unsigned n, unsigned k)
{
    if (i > n)
    {
        return;
    }

    loop1(i, 1, k);
    loop2(i + 1, n, k);
}

int main()
{
    unsigned n, k;
    cin >> n >> k;
    loop2(1, n, k);
    return 0;
}