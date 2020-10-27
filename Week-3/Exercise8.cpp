#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която по дадени 2 правоъгълника да изведе дали те се пресичат или не. 
Един правоъгълник се представя чрез координатите на горния му ляв и долния десен ъгъл.

Пояснение: Нека:

Lx1, Lу1 - х и у координати на горния ляв ъгъл на първия правоъгълник
Lх1, Lу1 - х и у координати на долния десен ъгъл на първия правоъгълник
Lx2, Lу2 - х и у координати на горния ляв ъгъл на втория правоъгълник
Lх2, Lу2 - х и у координати на долния десен ъгъл на втория правоъгълник
*/

bool doOverlapRectangles(int lx1, int ly1, int rx1, int ry1, int lx2, int ly2, int rx2, int ry2)
{
    if (lx1 >= rx2 || lx2 >= rx1)
        return false;

    if (ly1 <= ry2 || ly2 <= ry1)
        return false;

    return true;
}

int main()
{
    int lx1, ly1, rx1, ry1;
    int lx2, ly2, rx2, ry2;

    cin >> lx1 >> ly1 >> rx1 >> ry1 >> lx2 >> ly2 >> rx2 >> ry2;

    bool doOverlap = doOverlapRectangles(lx1, ly1, rx1, ry1, lx2, ly2, rx2, ry2);

    doOverlap ? cout << "YES" : cout << "NO";

    return 0;
}