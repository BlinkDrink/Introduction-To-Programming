#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool rectanglesOverlap(float lx1, float ly1, float rx1, float ry1, float lx2, float ly2, float rx2, float ry2)
{
    if (lx1 >= rx2 || lx2 >= rx1)
        return false;

    if (ly1 >= ry2 || ly2 >= ry1)
        return false;

    return true;
}

float min(float a, float b)
{
    return a < b ? a : b;
}

float max(float a, float b)
{
    return a > b ? a : b;
}

int main()
{
    float lx1, ly1, lx2, ly2, w1, h1, w2, h2, area;

    cin >> lx1 >> ly1 >> w1 >> h1 >> lx2 >> ly2 >> w2 >> h2;

    float rx1 = lx1 + w1;
    float ry1 = ly1 + h1;
    float rx2 = lx2 + w2;
    float ry2 = ly2 + h2;

    if (w1 <= 0 || h1 <= 0 || w2 <= 0 || h2 <= 0)
    {
        cout << "Invalid rectangle sides!";
        return 1;
    }

    if (rectanglesOverlap(lx1, ly1, rx1, ry1, lx2, ly2, rx2, ry2))
    {
        float overlapWidth = min(rx1, rx2) - max(lx1, lx2);
        float overlapHeight = min(ry1, ry2) - max(ly1, ly2);
        area = overlapHeight * overlapWidth;
    }
    else
    {
        area = 0;
    }

    cout << area;

    return 0;
}