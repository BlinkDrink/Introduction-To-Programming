#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int *divided[2];

void divideByHalf(const int *arr, unsigned size)
{
    unsigned elementsTillHalf = size / 2;
    unsigned elementsAfterHalf = size - elementsTillHalf;
    for (unsigned i = 0; i < size; i++)
    {
        divided[i] = &arr[i * size / 2];
    }
}

int main()
{
    const unsigned size = 7;
    const int *firstHalf, *secondHalf;

    int A[] = {-1, -2, -3, -4, -5, -6, -6};

    divideByHalf(A, size);

    return 0;
}