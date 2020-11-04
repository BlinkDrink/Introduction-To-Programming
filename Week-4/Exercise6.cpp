#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се пресметнат и отпечатат първите n членa на редицата a_i = i^2 + 3*i за въведено i.
*/

int main()
{
    unsigned i;
    cin >> i;

    for (int k = 1; k <= i; k++)
    {
        cout << "a_" << k << "= " << (k * k) + (3 * k) << endl;
    }

    return 0;
}