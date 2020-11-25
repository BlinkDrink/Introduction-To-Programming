#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която приема масив и връща средното аритметично от 
произведението на числата на позиции (0 + n), (1 + (n - 1)) и тн. Пример: [1, 10, 4, 2, 21, 4]

Изход: 74 (1 * 4 + 10 * 21 + 4 * 2) / 3
*/

void arrInput(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int productAverage(int arr[], unsigned size)
{
    int product = 0;
    int count = 0;
    for (int i = 0; i < size / 2; i++)
    {
        product += arr[i] * arr[size - 1 - i];
        count++;
    }

    return product / count;
}

int main()
{
    unsigned const ARR_SIZE = 6;
    int arr[ARR_SIZE];

    arrInput(arr, ARR_SIZE);
    cout << productAverage(arr, ARR_SIZE);
}