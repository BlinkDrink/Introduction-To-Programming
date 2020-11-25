#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 1000;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void reverseArr(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[MAX_SIZE];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseArr(arr, n);
    printArr(arr, n);
}
