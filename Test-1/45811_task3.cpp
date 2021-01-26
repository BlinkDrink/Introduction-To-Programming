#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 1
// 2020-11-29
//
// Начален час на контролното: 9:00
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Използван компилатор: mingw-w64
//
const long MAX_SIZE = 1000000;

void readArray(float arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

float absValue(float a, float b)
{
    float diff = a - b;
    return diff < 0 ? -diff : diff;
}

int absValueInt(int a, int b)
{
    int diff = a - b;
    return diff < 0 ? -diff : diff;
}

int main()
{
    long n, resArrIndex = 0;
    do
    {
        cin >> n;
    } while (n < 1 || n > MAX_SIZE);

    float arr[50];
    unsigned distanceArr[50];
    unsigned diffArr[50];
    readArray(arr, n);

    bool appliedForAll = true;
    float diff = 0;
    float diffPerStep = 0;

    // for (unsigned i = 0; i < n - 1; i++)
    // {
    //     float currEl = arr[i];

    //     for (unsigned j = 1; j < n - 1; j++)
    //     {

    //         for (unsigned k = 1; k < n - 1; k += j)
    //         {
    //             diff = absValue(currEl, arr[j]);
    //             if (diff != absValue(currEl, arr[k]))
    //             {
    //                 break;
    //             }
    //         }
    //     }
    //     if (diff != absValue(currEl, arr[j + 1]))
    //     {
    //         appliedForAll = false;
    //     }
    //     if (appliedForAll)
    //     {
    //         distanceArr[resArrIndex] = absValueInt(j, i);
    //         diffArr[resArrIndex++] = diff;
    //     }
    // }

    float nextDiff = 0;
    unsigned lastIndex = 0;
    unsigned step = 0;
    for (unsigned i = 1; i < n; i++)
    {
        float diff = absValue(arr[i - 1], arr[i + step]);
        float currEl = arr[i - 1];
        for (unsigned k = 1; k < n; k++)
        {
            for (unsigned j = 1; j < n; j += k)
            {
                if (absValue(arr[i], arr[j - 1]) != diff)
                {
                    appliedForAll = false;
                }
                lastIndex = j;
            }
            if (appliedForAll)
            {
                distanceArr[resArrIndex] = absValueInt(lastIndex, i);
                diffArr[resArrIndex++] = diff;
            }
            step++;
        }
    }

    unsigned maxDistance = 0;
    for (unsigned i = 0; i < resArrIndex; i++)
    {
        if (distanceArr[i] > distanceArr[maxDistance])
        {
            maxDistance = i;
        }
    }

    cout << distanceArr[maxDistance] << " " << diffArr[maxDistance];

    return 0;
}