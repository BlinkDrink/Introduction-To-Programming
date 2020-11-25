#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

/*
Дадени са три двойки числа с плаваща точка – координати на три точки в равнината. Проверете дали
трите точки са върхове на правоъгълен триъгълник.


Вход:    Изход:         Вход:       Изход:
1.12 0    Yes           1 1         No
0 2.2                   2 2
0 0                     2 5

*/

int main()
{
    float x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    float side1 = ((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    float side2 = ((y3 - y2) * (y3 - y2) + (x3 - x2) * (x3 - x2));
    float side3 = ((y3 - y1) * (y3 - y1) + (x3 - x1) * (x3 - x1));

    if ((side1 > 0 && side2 > 0 && side3 > 0) && (side1 == (side2 + side3) || side2 == (side1 + side3) || side3 == (side1 + side2)))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}