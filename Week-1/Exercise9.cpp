#include <iostream>
#include <cmath>

/*
Следствие на задача 8.
Нека се въведе още 1 число m: m > n. Да се намери сумата на числата в интервала [n, m].

Пример: n = 5, m = 10. Тогава сумата е: 5 + 6 + 7 + 8 + 9 + 10 = 45
*/

int main()
{
    int n, m;
    std::cin >> n >> m;

    int sum_n_minus_1 = ((n - 1) * (n - 1 + 1)) / 2;
    int sum_n_to_m = ((m * (m + 1)) / 2) - sum_n_minus_1;

    std::cout
        << "Sum of the numbers in the interval [" << n << ", " << m << "] is: " << sum_n_to_m;

    return 0;
}
