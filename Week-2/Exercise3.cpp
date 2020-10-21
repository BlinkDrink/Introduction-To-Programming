#include <iostream>

/*
Напишете програма, която при въведен радиус r и координати на точка x y, определя, дали точката се 
намира в окръжност с център (0,0) и радиус r.

Пример: Вход: 3 2 2 Изход: true Вход: 2 1 -2 Изход: false
*/

int main()
{
    double r, x, y;
    std::cin >> r >> x >> y;

    double distanceToPoint = r * r - ((x * x) + (y * y));

    if (distanceToPoint > 0)
        std::cout << "true";
    else if (distanceToPoint == 0)
        std::cout << "The point lies on the circumference.";
    else
        std::cout << "false";

    return 0;
}
