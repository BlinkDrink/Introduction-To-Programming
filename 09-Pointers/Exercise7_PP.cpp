#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int *concatArrays(int *firstArr, unsigned firstSize, int *secondArr, unsigned secondSize)
{
    int *concArrays = new int[firstSize + secondSize];

    for (unsigned i = 0; i < firstSize; i++)
    {
        concArrays[i] = firstArr[i];
    }
    for (unsigned i = 0; i < secondSize; i++)
    {
        concArrays[i + firstSize] = secondArr[i];
    }

    return concArrays;
}

int main()
{
    const unsigned aSize = 7;
    const unsigned bSize = 5;
    int A[] = {-1, -2, -3, -4, -5, -6, -7};
    int B[] = {3, 7, 8, 10, 15};

    int *concatenated = nullptr;
    concatenated = concatArrays(A, aSize, B, bSize);

    for (unsigned i = 0; i < aSize + bSize; i++)
    {
        cout << concatenated[i] << " ";
    }

    return 0;
}