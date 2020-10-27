#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която по въведени координати на точка от равнината да изведе 
на кой квадрант принадлежи тя. Да се разгледат случаите, когато точката принадлежи 
на някоя от координатните оси или съвпада с центъра на координатната система.

Примери

Вход: 1 2

Изход: First Quadrant

Вход: 0 -3

Изход: X axis7
*/

int main()
{
    int x, y;
    cin >> x >> y;

    if (x > 0 && y > 0)
        cout << "First Quadrant";

    else if (x < 0 && y > 0)
        cout << "Second Quadrant";

    else if (x < 0 && y < 0)
        cout << "Third Quadrant";

    else if (x > 0 && y < 0)
        cout << "Fourth Quadrant";

    else if (x == 0 && y > 0)
        cout << "positive y axis";

    else if (x == 0 && y < 0)
        cout << "negative y axis";

    else if (y == 0 && x < 0)
        cout << "negative x axis";

    else if (y == 0 && x > 0)
        cout << "positive x axis";

    else
        cout << "lies at origin(0,0)";

    return 0;
}