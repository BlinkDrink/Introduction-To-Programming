#include <iostream>
using namespace std;

bool CheckNum(int num)
{
    int ind = 1;

    while (num != 0)
    {
        int digit = num % 10;

        if (ind % 2 == 1 && digit % 2 == 0 || ind % 2 == 0 && digit % 2 != 0)
        {
            return false;
        }
        ind++;
        num /= 10;
    }

    return true;
}

int main()
{
    int N, M;
    cin >> M >> N;

    if (M > N)
    {
        swap(M, N);
    }

    for (int i = M; i < N; i++)
    {
        if (CheckNum(i))
        {
            cout << i << ' ';
        }
    }

    return 0;
}