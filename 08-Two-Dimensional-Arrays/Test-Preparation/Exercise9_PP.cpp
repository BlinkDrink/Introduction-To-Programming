#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Коледа наближава и искаме да зарадваме максимално много приятели като им подарим подарък. 
По даден масив от числа с плаваща запетая: gifts - цените на подаръци и число с плаваща запетая:
budget - парична сума с която разполагаме. Тъй като искаме да зарадваме максимално много хора искаме
да купим възможно най-много подаръци с бюджета с който разполагаме. Да се изведат на екрана цените 
на подаръците които ще купим.
*/

const unsigned MAX_SIZE = 50;

void swap(float &a, float &b)
{
    float tmp = a;
    a = b;
    b = tmp;
}

void sort(float gifts[], unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < n; j++)
        {
            if (gifts[j] > gifts[i])
            {
                swap(gifts[i], gifts[j]);
            }
        }
    }
}

int main()
{
    unsigned n, sum = 0, giftsResIndex = 0;
    float budget;
    float gifts[MAX_SIZE];
    float giftsRes[MAX_SIZE];
    cin >> n >> budget;

    for (unsigned i = 0; i < n; i++)
    {
        cin >> gifts[i];
    }

    sort(gifts, n);

    for (unsigned i = 0; i < n; i++)
    {
        if (sum + gifts[i] <= budget)
        {
            giftsRes[giftsResIndex++] = gifts[i];
            sum += gifts[i];
        }
    }

    for (unsigned i = 0; i < giftsResIndex; i++)
    {
        cout << giftsRes[i] << " ";
    }

    return 0;
}
