#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void resize(int *arr, unsigned size, unsigned newSize)
{
    int *copy = new int[size];

    for (unsigned i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }

    arr = new int[newSize];

    for (unsigned i = 0; i < newSize; i++)
    {
        arr[i] = copy[i];
    }
    delete[] copy;
}

int main()
{
    const unsigned aSize = 7;
    int A[] = {-1, -2, -3, -4, -5, -6, -7};

    resize(A, aSize, 5);
    for (unsigned i = 0; i < 5; i++)
    {
        cout << A[i];
    }

    return 0;
}