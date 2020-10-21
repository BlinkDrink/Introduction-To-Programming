#include <iostream>
#include <cmath>

/*
Работим в двумерна декартова координатна система.

По дадени x и y координатите на две точки, да се намери разстоянието между тях.

Пример: А(0, 0), B(3, 4)
distance(A, B) = 5
*/

int main()
{
    float x1, y1, x2, y2;

    std::cout << "Enter the coordinates for A(x1,x2) and B(x2,y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;

    float distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    std::cout << "distance(A,B): " << distance;

    return 0;
}
