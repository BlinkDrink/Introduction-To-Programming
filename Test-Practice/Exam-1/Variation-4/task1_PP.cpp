#include <iostream>
using namespace std;

int main()
{
    const double EPS = 0.0001;
    double a1, b1, c1, a2, b2, c2;
    std::cout << "Enter the six coefficient A1, B1, C1, A2, B2, C2 of the line equations:";
    std::cout << "A1*x + B1*y + C1 = 0 and A2*x + B2*x + C2 = 0:" << std::endl;
    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

    // To get the intersection point we must solve the system
    // | A1*x + B1*y + C1 = 0
    // | A2*x + B2*x + C2 = 0
    // To solve it we can use Cramer's rule:
    double determinant = a1 * b2 - b1 * a2;
    double intersectionX = ((c1 * b2) - (c2 * b1)) / determinant;
    double intersectionY = ((a1 * c2) - (c1 * a2)) / determinant;

    if (abs(determinant) < EPS)
        std::cout << "Parallel" << std::endl;
    else
        std::cout << "The lines intersect at (" << intersectionX << ", " << intersectionY << ")" << std::endl;

    return 0;
}
