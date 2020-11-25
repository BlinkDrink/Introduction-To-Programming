#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 7;
/*
Прочетете от стандартния вход две числа A и B и намерете броя на целите числа в интервала [A, B), такива
че се състоят само от различни цифри.

Вход:       Изход:
120 125     3
*/
bool digitsAreDifferent(int n)
{
    int arr[MAX_SIZE];
    int counter = 0;

    while (n != 0)
    {
        arr[counter++] = n % 10;
        n /= 10;
    }

    for (int i = 0; i < counter; i++)
    {
        int el = arr[i];
        for (int j = 0; j < counter; j++)
        {
            if (i != j)
                if (arr[i] == arr[j])
                    return false;
        }
    }

    return true;
}

int main()
{
    int A, B, counter = 0;
    cin >> A >> B;

    for (int i = A; i < B; i++)
    {
        if (digitsAreDifferent(i))
            counter++;
    }

    cout << counter;

    return 0;
}