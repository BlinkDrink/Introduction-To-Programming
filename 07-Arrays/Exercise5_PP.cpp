#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете функция, която намира най-голямото произведение на които и да са две числа от масива.
Напишете отделна функция за въвеждането на масива. Вход: [1, 4, -10, -1, 3, 10, -5] Изход: 50
*/

void arrInput(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int biggestProduct(int arr[], unsigned size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        for (int k = i + 1; k < size; k++)
        {
            int product = arr[i] * arr[k];

            if (max < product)
                max = product;
        }
    }

    return max;
}

int main()
{
    unsigned const ARR_SIZE = 7;
    int arr[ARR_SIZE];

    arrInput(arr, ARR_SIZE);
    cout << biggestProduct(arr, ARR_SIZE);
}