#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Играем следната игра: Пешо си намисля число в интервала от 1 до 100. Ванката задава въпроси от рода на
"Твоето число по-голямо ли е от X?", където X е число в интервала. За всеки отговор Ванката трябва да
плати на Пешо по 1 лев. Помогнете на Ванката като напишете функция която с възможно най-малко пари 
винаги познава числото на Пешо.
*/

const int MAX_SIZE = 100;

int binarySearch(int l, int r, int x, unsigned &guesses)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (mid == x)
            return mid;

        if (mid > x)
        {
            guesses++;
            return binarySearch(l, mid, x, guesses);
        }

        guesses++;
        return binarySearch(mid, r, x, guesses);
    }

    return -1;
}

unsigned guessPeshosNumber(unsigned n, unsigned peshosNumber)
{
    unsigned guesses = 0;

    binarySearch(1, n, peshosNumber, guesses);

    return guesses;
}

int main()
{
    unsigned peshosNumber;
    cin >> peshosNumber;

    cout << "Guesses: " << guessPeshosNumber(MAX_SIZE, peshosNumber);

    return 0;
}
