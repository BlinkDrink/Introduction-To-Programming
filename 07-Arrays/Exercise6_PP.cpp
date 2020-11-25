#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Наишете функция, която приема масив с числа и отпечатва всички възможни пермутации с тези стойности.
*/
void arrInput(int[], unsigned);
void sort(int[], unsigned);
void swap(int &, int &);
void possiblePermutations(int[], int, unsigned);

int main()
{
    unsigned const ARR_SIZE = 5;
    int i = 0;
    int arr[ARR_SIZE];

    arrInput(arr, ARR_SIZE);
    sort(arr, ARR_SIZE);
    possiblePermutations(arr, i, ARR_SIZE);
}

void arrInput(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void sort(int arr[], unsigned size)
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
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void possiblePermutations(int arr[], int i, unsigned size)
{
    int j;
    if (i == size)
    {
        for (int l = 0; l < size; l++)
        {
            cout << arr[l];
        }
        cout << endl;
    }
    else
    {
        for (j = i; j < size; j++)
        {
            swap(arr[i], arr[j]);
            possiblePermutations(arr, i + 1, size);
            swap(arr[i], arr[j]);
        }
    }
}