#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

/*
Дадени са три двойки числа с плаваща точка – координати на три точки в равнината. Проверете дали
трите точки лежат на една права. Изведете "Yes" ако лежат и "No" ако не лежат.
Пример:
Вход:1.5 1.5     Изход: Yes
     2.2 2.2 
     3.5 3.5   
Вход:1 1        Изход: No
     2 2
     2 5
*/

int main()
{
    float x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Checking if the distance between the sum of the first two lines equals the whole line.
    float distanceP1andP2 = sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)); // AB
    float distanceP2andP3 = sqrt((y3 - y2) * (y3 - y2) + (x3 - x2) * (x3 - x2)); // BC
    float distanceP1andP3 = sqrt((y3 - y1) * (y3 - y1) + (x3 - x1) * (x3 - x1)); // AC

    if (distanceP1andP2 + distanceP2andP3 == distanceP1andP3)
    {
        cout << "Yes";
        return 0;
    }

    cout << "No";
    return 0;
}