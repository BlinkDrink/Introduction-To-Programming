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

void print(int *arr, unsigned size, int step)
{
    if (step == size)
    {
        return;
    }

    cout << *arr << " ";

    print(arr + 1, size, step + 1);
}

bool isSorted(int *arr, unsigned size, unsigned i, unsigned j)
{
    if (i >= size || j >= size)
    {
        return false;
    }
    if (arr[i] > arr[j])
    {
        return false;
    }
    if (arr[size - 2] <= arr[size - 1])
    {
        return true;
    }

    return isSorted(arr, size, i + 1, j + 1);
}

void shiftElementsRight(int *arr, int step, unsigned startingIndex)
{
    if (step < 0)
    {
        return;
    }

    if (startingIndex == step)
    {
        swap(arr[step], arr[step + 1]);
        return;
    }
    swap(arr[step - 1], arr[step]);

    shiftElementsRight(arr, step - 1, startingIndex);
}

bool insertInSorted(int *arr, unsigned size, unsigned insertAtIndex, unsigned step, int element)
{
    if (step >= size)
    {
        return false;
    }
    if (step == insertAtIndex)
    {
        shiftElementsRight(arr, size, insertAtIndex);
        arr[insertAtIndex] = element;
    }
    return insertInSorted(arr, size, insertAtIndex, step + 1, element);
}

int main()
{
    unsigned n;
    const unsigned MAX_SIZE = 1000;
    do
    {
        cin >> n;
    } while (n > MAX_SIZE);

    int *arr = new (std::nothrow) int[n];
    for (size_t i = 0; i < n; i++)
    {
        int toInsert;
        cin >> toInsert;
        insertInSorted(arr, n, i, 0, toInsert);
    }

    print(arr, n, 0);
    cout << endl;
    cout << isSorted(arr, n, 0, 1);

    print(arr, n, 0);

    return 0;
}