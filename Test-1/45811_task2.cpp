#include <iostream>

using std::cin;
using std::cout;

//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 1
// 2020-11-29
//
// Начален час на контролното: 9:00
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Използван компилатор: mingw-w64
//

bool isPrime(int counter)
{
    if (counter == 0 || counter == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= counter; i++)
    {
        if (counter % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool countIsPrime(int n)
{
    unsigned counter = 0;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            counter++;
        }
    }

    return isPrime(counter);
}

int main()
{
    int a, b;
    cin >> a >> b;
    if (a > b)
    {
        cout << "Incorrect input.";
        return 1;
    }

    unsigned counter = 0;

    for (int i = a; i <= b; i++)
    {
        if (countIsPrime(i))
        {
            counter++;
        }
    }

    cout << counter;

    return 0;
}