#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която намира втория по големина елемент в от масив.
Използвайте функция за въвеждането на числата в масива.
*/

void arrInput(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int secondBiggestElement(int arr[], unsigned size)
{
    int j;
    for (int i = 1; i < size; i++)
    {
        int currentElement = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > currentElement)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = currentElement;
    }

    return arr[size - 2];
}

int main()
{
    unsigned const ARR_SIZE = 10;
    int arr[ARR_SIZE];

    arrInput(arr, ARR_SIZE);
    cout << secondBiggestElement(arr, ARR_SIZE);
}