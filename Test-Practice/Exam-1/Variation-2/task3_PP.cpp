#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const size_t MAX_SIZE = 5000;
/*
Въведете цяло число N, не по-голямо от 5000, следвано от N цели числа. Съхранете ги в масив. Изведете
го на екрана. След това след всяко число, което е четно вмъкнете нов елемент, равен на половината му, а след
всяко нечетно – сумата на всички по-малки от него нечетни числа. Изведете резултата на екрана.
Пример:
Вход:                       Изход:
10                         1 2 3 3 2 4 2 1 2 3                       
1 2 3 3 2 4 2 1 2 3        1 0 2 1 3 2 3 2 2 1 4 2 2 1 1 0 2 1 3 2   
*/
size_t readSize()
{
    size_t N;
    do
    {
        cout << "N=";
        cin >> N;
    } while (N < 1 || N > MAX_SIZE);

    return N;
}

void readArray(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        cin >> arr[i];
}

void printArray(int arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int sumOfOddNumsLessThan(int arr[], size_t size, int x)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0 && arr[i] < x)
            sum += arr[i];
    }
    return sum;
}

int modifyArray(int arr[], int resultArr[], size_t size)
{
    int newSize = 0;
    for (size_t i = 0; i < size; i++)
    {
        resultArr[newSize] = arr[i];
        if (arr[i] % 2 == 0)
        {
            resultArr[newSize + 1] = arr[i] / 2;
            newSize++;
        }
        else
        {
            resultArr[newSize + 1] = sumOfOddNumsLessThan(arr, size, arr[i]);
            newSize++;
        }

        newSize++;
    }

    return newSize;
}

int main()
{
    size_t N;
    int arr[MAX_SIZE];
    int resultArr[MAX_SIZE];
    N = readSize();
    readArray(arr, N);
    printArray(arr, N);

    int newSize = modifyArray(arr, resultArr, N);
    printArray(resultArr, newSize);

    return 0;
}