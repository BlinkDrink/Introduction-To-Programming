#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която проверява дали дадено число се среща в масив.
Ако се среща изведете неговата позиция, в противен случай -1.
*/

void arrInput(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int indexOf(int arr[], unsigned size, int elementToFind)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elementToFind)
            index = i;
    }

    return index;
}

int main()
{
    unsigned const ARR_SIZE = 10;
    int arr[ARR_SIZE];
    int elementToFind = 0;

    arrInput(arr, ARR_SIZE);
    cin >> elementToFind;
    cout << indexOf(arr, ARR_SIZE, elementToFind);
}