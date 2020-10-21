#include <iostream>
#include <cmath>

// По дадени 3 страни на триъгилник намерете периметъра и лицето му.

int main()
{
    double a, b, c;
    std::cin >> a >> b >> c;

    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    std::cout << "Perimeter = " << p * 2 << std::endl;
    std::cout << "Area = " << area;

    return 0;
}
