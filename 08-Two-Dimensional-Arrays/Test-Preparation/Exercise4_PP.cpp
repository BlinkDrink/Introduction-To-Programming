#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Дадени за два вектора във вида на масиви. Намерете скаларното произведение на тези 2 вектора. ab=a1b1+a2b2+...+anbn
*/
const int MAX_SIZE = 50;
bool isPrimeNumber(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int size, result = 0;
    int v1[MAX_SIZE], v2[MAX_SIZE];
    cout << "Enter size of v1 and v2:";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> v1[i];
    }

    for (int i = 0; i < size; i++)
    {
        cin >> v2[i];
    }

    for (int i = 0; i < size; i++)
    {
        result += v1[i] * v2[i];
    }

    cout << result;

    return 0;
}