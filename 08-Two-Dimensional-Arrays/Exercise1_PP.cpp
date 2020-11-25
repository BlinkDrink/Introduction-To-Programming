#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Напишете програма, която проверява коя цифра на дадено неотрицателно число се среща най-много пъти в десетиянич му запис.

ВХОД:
1231
ИЗХОД:
1
2
*/

short getNumOfDigits(int n)
{
    short digits = 0;
    while (n != 0)
    {
        digits++;
        n /= 10;
    }
    return digits;
}

short indexOfMostRepeated(short a[], int size)
{
    int max = 0;
    int index = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int n, copyN, secondCopy;
    cin >> n;
    copyN = n;
    secondCopy = n;

    short mapDigitKeys[20];
    short mapRepeatedValues[20] = {
        0,
    };

    short numberOfDigits = getNumOfDigits(n);

    for (int i = 0; i < numberOfDigits; i++)
    {
        short currentDigit = secondCopy % 10;
        mapDigitKeys[i] = currentDigit;
        while (copyN != 0)
        {
            if (copyN % 10 == currentDigit)
            {
                mapRepeatedValues[i]++;
            }

            copyN /= 10;
        }
        copyN = n;
        secondCopy /= 10;
    }

    int indexMostRepeated = indexOfMostRepeated(mapRepeatedValues, numberOfDigits);
    cout << mapDigitKeys[indexMostRepeated] << endl
         << mapRepeatedValues[indexMostRepeated];
}