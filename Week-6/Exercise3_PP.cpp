#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която намира броя на елементите от даден масив, които са по-гоеми от съседите си.
Използвайте функция за въвеждането на числата в масива.

Вход: 5 6 4 10 5 3

Изход: 2
*/

void arrInput(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int elementsBiggerThanNeighbour(int arr[], unsigned size)
{
    unsigned elements = 0;
    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[+1])
            elements++;
    }

    return elements;
}

int main()
{
    unsigned const ARR_SIZE = 10;
    int arr[ARR_SIZE];

    arrInput(arr, ARR_SIZE);
    cout << elementsBiggerThanNeighbour(arr, ARR_SIZE);
}