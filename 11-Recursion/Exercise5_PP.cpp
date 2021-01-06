#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char popFromStack(unsigned n, char *column)
{
    for (unsigned i = n - 1; i >= 0; i--)
    {
        if (column[i] != '0')
        {
            char tmp = column[i];
            column[i] == '0';
            return tmp;
        }
    }

    return '0';
}

char *pushOnStack(unsigned n, char *from, char *to)
{
    char *iter;
    for (iter = to; *iter != '\0'; iter++)
    {
        if (*iter == '0')
        {
            *iter = popFromStack(n, from);
            break;
        }
    }

    return to;
}

bool isComplete(unsigned n, char *column)
{
    for (unsigned i = 0; i < n; i++)
    {
        if ((column[i] - '0') != n - i)
        {
            return false;
        }
    }
    return true;
}

bool isEmpty(unsigned n, char *column)
{
    for (unsigned i = 0; i < n; i++)
    {
        if (column[i] != '0')
            return false;
    }
    return true;
}

char *findNonEmptyColumn(unsigned n, char *A, char *B, char *C)
{
    if (!isEmpty(n, A))
    {
        return A;
    }
    else if (!isEmpty(n, B))
    {
        return B;
    }
    else
    {
        return C;
    }
}

char *findEmptyColumn(unsigned n, char *A, char *B, char *C)
{
    if (isEmpty(n, A))
    {
        return A;
    }
    else if (isEmpty(n, B))
    {
        return B;
    }
    else
    {
        return C;
    }
}

void playHanoy(unsigned n, char *A, char *B, char *C)
{
    if (isComplete(n, B) || isComplete(n, C))
    {
        return;
    }

    pushOnStack(n, A, B);
    playHanoy(n, A, B, C);
}

int main()
{
    unsigned n;
    cin >> n;

    char *A = new char[n];
    char *B = new char[n];
    char *C = new char[n];

    A[n] = '\0';
    B[n] = '\0';
    C[n] = '\0';

    for (unsigned i = 0; i < n; i++)
    {
        A[i] = (n - i) + '0';
        B[i] = '0';
        C[i] = '0';
    }

    playHanoy(n, A, B, C);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}