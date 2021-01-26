#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Използван компилатор: mingw-64
//

unsigned checkNumsRec(int *nums, unsigned size)
{
    //TODO
    checkNumsRec(nums, size);
}

int main()
{
    const unsigned MAX_SIZE = 20;
    unsigned n;
    do
    {
        cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    int *nums = new (std::nothrow) int[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    delete[] nums;

    return 0;
}