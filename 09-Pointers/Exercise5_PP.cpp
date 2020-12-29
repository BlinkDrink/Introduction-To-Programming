#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int *adjacent_find(const int *begin, const int *end)
{
    for (const int *fStart = begin; fStart < end - 1; fStart++)
    {
        if (*fStart == fStart[1]) // Can also be written as: if(*fStart == *(fstart+1))
            return fStart;
    }
    return nullptr;
}

int main()
{
    const unsigned size = 7;
    int A[] = {-1, -2, -3, -4, -5, -6, -6};

    const int *found = adjacent_find(A, A + size);
    cout << (found == nullptr ? 0 : *found);

    return 0;
}