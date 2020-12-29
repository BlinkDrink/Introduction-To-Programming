#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printArrayByIndex(int arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        cout << arr[i];
    }
}

void printArrayByPointer(int *arr, unsigned size)
{
    for (int *end = arr + size; arr < end; arr++)
    {
        cout << *arr << " ";
    }

    cout << '\n';
}

void printArrayByHelperPointer(int *arr, unsigned size)
{
    for (int *iter = arr; iter < arr + size; iter++)
    {
        cout << *iter;
    }
}

int main()
{
    const unsigned size = 4;
    int A[4] = {-1, -2, -3, -4};
    int B[4] = {10, 20, 30, -1};

    //printArrayByIndex(A, size);
    printArrayByPointer(B, size);
    //printArrayByHelperPointer(A, size);

    return 0;
}