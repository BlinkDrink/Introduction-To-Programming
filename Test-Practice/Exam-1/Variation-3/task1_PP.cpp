#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    float a, x, b, y, c, a1, b1, c1;
    cin >> a >> b >> c >> a1 >> b1 >> c1;

    //a1*(-c-b*y)/a + b1*y= c1
    float determinant = (a * b1) - (b * a1);
    float x_determinant = (c * b1) - (b * c1);
    float y_determinant = (a * c1) - (c * a1);

    if (x_determinant == 0 || y_determinant == 0)
    {
        cout << "Infinty solutions. Lineary dependent";
    }
    else if (determinant != 0)
    {
        x = x_determinant / determinant;
        y = y_determinant / determinant;

        cout << "X = " << x << endl
             << "Y = " << y;
    }
    else
    {
        cout << "No solution!";
    }
}