#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const size_t MAX_SIZE = 1000;
/*
Въведете цяло число N, не по-голямо от 1000, следвано от N числа с плаваща точка. Съхранете ги в масив.
Изведете го на екрана. След това премахнете всички числа от масива, по-малки от средно-аритметичното на всички
въведени числа и отново изведете числата на екрана.

Вход:                   Изход:
10 
1 2 3 3 2 4 2 1 2 3     1 2 3 3 2 4 2 1 2 3 
                        3 3 4 3                    
*/
size_t readSize()
{
    size_t N;
    do
    {
        cout << "N = ";
        cin >> N;
    } while (N == 0 || N > 1000);

    return N;
}

void readArray(float arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

float getSum(float arr[], size_t size)
{
    float sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void printArray(float arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    size_t N;
    float average, sum;
    float arr[MAX_SIZE], resultArr[MAX_SIZE];
    int resultArrCounter = 0;

    N = readSize();
    readArray(arr, N);
    printArray(arr, N);
    sum = getSum(arr, N);
    average = sum / N;

    for (size_t i = 0; i < N; i++)
    {
        if (arr[i] >= average)
        {
            resultArr[resultArrCounter++] = arr[i];
        }
    }

    printArray(resultArr, resultArrCounter);
    return 0;
}