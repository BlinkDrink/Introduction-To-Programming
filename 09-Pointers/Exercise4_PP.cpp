#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int *findFirstOf(const int *begin, const int *end, const int *sBegin, const int *sEnd)
{
    for (const int *fStart = begin; fStart < end; fStart++)
    {
        for (const int *sStart = sBegin; sStart < sEnd; sStart++)
        {
            if (*sStart == *fStart)
                return sStart;
        }
    }
    return nullptr;
}

int main()
{
    const unsigned size = 4;
    int A[4] = {-1, -2, -3, -4};
    int B[4] = {10, 20, 30, -1};

    const int *found = findFirstOf(A, A + size, B, B + size);
    cout << (found == nullptr ? 0 : *found);

    return 0;
}