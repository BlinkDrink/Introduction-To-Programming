#include <iostream>

using std::abs;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::swap;

const unsigned MAX_SIZE = 8192 * 2; // * 2 because when multiplying it can exceed 16000

char a[MAX_SIZE];
char b[MAX_SIZE];
char result[MAX_SIZE];
char tmp1Num[MAX_SIZE / 2]; // Used in multiplying
char tmp2Num[MAX_SIZE / 2];

unsigned getSize(char arr[])
{
    unsigned count = 0;
    for (unsigned i = 0; i < MAX_SIZE; i++)
    {
        if (arr[i] == '\0')
        {
            return count;
        }

        count++;
    }
    return count;
}

bool isValid(char arr[], char size)
{
    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i] < '0' || arr[i] > '9')
        {
            return false;
        }
    }
    return true;
}

void printArray(char arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
        cout << arr[i];
}

void clearArray(char arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        arr[i] = '\0';
    }
}

void reverseArr(char arr[], unsigned size)
{
    for (unsigned i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
}

/**
 * Checks if two arrays are identical.
 * 
 * @param first First array
 * @param second Second array
 * @param fstSize Size of first array
 * @param sndSize Size of second array
 * 
 * @return true if identical, false if not
 */
bool areEqual(char first[], char second[], unsigned fstSize, unsigned sndSize)
{
    bool areNumsEqual = false;
    if (fstSize != sndSize)
    {
        return false;
    }

    for (unsigned i = 0; i < fstSize; i++)
    {
        if (first[i] != second[i])
        {
            return false;
        }
    }

    return true;
}

/**
 * Prints arrays in format: first 'operation' second 
 */
void printFormat(char first[], char second[], unsigned fstSize, unsigned sndSize, char operation)
{
    for (unsigned i = 0; i < fstSize; i++)
    {
        cout << first[i];
    }

    if (operation == '!')
    {
        cout << ' ' << operation << "= ";
    }
    else if (operation == '=')
    {
        cout << ' ' << operation << "= ";
    }
    else
    {
        cout << ' ' << operation << ' ';
    }

    for (unsigned i = 0; i < sndSize; i++)
    {
        cout << second[i];
    }
}

/**
 * Formats char array with leading zeros.
 * 
 * @param arr The array to be formated
 * @param size Size of the array
 * @return The new size of the formated array
 */
unsigned formatArray(char arr[], unsigned size)
{
    unsigned leftMostDigitIndex = 0;

    for (unsigned i = 0; i < size; i++)
    {
        if (arr[i] != '0')
        {
            leftMostDigitIndex = i;
            break;
        }
    }

    for (unsigned i = 0; i < size; i++)
    {
        swap(arr[i], arr[leftMostDigitIndex + i]);
    }

    return size - leftMostDigitIndex;
}

/**
 * Compares numbers first and second in char array format.
 * 
 * @param aSize Size of character array first.
 * @param bSize Size of character array second.
 * @return 0 if first==second, -1 if second>first, 1 if first>second.
 */
int numberComparison(char first[], char second[], unsigned fstSize, unsigned sndSize)
{
    int flag = 0;
    if (areEqual(first, second, fstSize, sndSize))
    {
        return 0;
    }

    if (sndSize > fstSize)
    {
        return -1;
    }

    if (fstSize > sndSize)
    {
        return 1;
    }

    if (fstSize == sndSize)
    {
        for (unsigned i = 0; i < fstSize; i++)
        {
            unsigned aInt = a[i] - '0';
            unsigned bInt = b[i] - '0';
            if (aInt == bInt)
            {
                continue;
            }
            else if (aInt > bInt)
            {
                flag = 1;
                return flag;
            }
            else
            {
                flag = -1;
                return flag;
            }
        }
    }

    return flag;
}

unsigned add(char resultArr[], char maxArr[], char minArr[], unsigned maxSize, unsigned minSize)
{
    unsigned resultSize = 0;
    unsigned carryIn = 0;
    for (unsigned i = 0; i < maxSize; i++)
    {
        if (i >= minSize)
        {
            unsigned sum = (maxArr[i] - '0') + carryIn;
            resultArr[resultSize++] = (sum % 10) + '0';
            carryIn = sum / 10;
        }
        else
        {
            unsigned short sum = ((int)(maxArr[i] - '0') + (int)(minArr[i] - '0')) + carryIn;
            if (sum < 10)
            {
                resultArr[resultSize++] = sum + '0';
                carryIn = sum / 10;
            }
            else
            {
                resultArr[resultSize++] = (sum % 10) + '0';
                carryIn = sum / 10;
            }
        }
    }

    if (carryIn != 0)
    {
        resultArr[resultSize++] = carryIn + '0';
    }
    return resultSize;
}

unsigned subtract(char resultArr[], char maxArr[], char minArr[], unsigned maxSize, unsigned minSize)
{
    unsigned resultSize = 0;
    unsigned carryIn = 0;
    for (unsigned i = 0; i < maxSize; i++)
    {
        if (i >= minSize)
        {
            short difference = (maxArr[i] - '0') - carryIn;
            if (difference < 0)
            {
                resultArr[resultSize++] = (10 - abs(difference)) + '0';
                carryIn = 1;
            }
            else
            {
                resultArr[resultSize++] = (abs(difference)) + '0';
                carryIn = 0;
            }
        }
        else
        {
            short difference = ((maxArr[i] - '0') - (minArr[i] - '0')) - carryIn;
            if (difference < 0)
            {
                resultArr[resultSize++] = (10 - abs(difference)) + '0';
                carryIn = 1;
            }
            else
            {
                resultArr[resultSize++] = (abs(difference)) + '0';
                carryIn = 0;
            }
        }
    }
    if (carryIn != 0)
    {
        resultArr[resultSize++] = carryIn + '0';
    }

    return resultSize;
}

unsigned multiply(char resultArr[], char maxArr[], char minArr[], unsigned maxSize, unsigned minSize)
{
    unsigned tmpResultSize = 0;

    tmp2Num[0] = '0';

    for (int i = maxSize - 1; i >= 0; i--)
    {
        short maxArrCurrDig = maxArr[i] - '0';
        short carryIn = 0;
        int tmp1Size = 0;

        for (int j = minSize - 1; j >= 0; j--)
        {
            short minArrCurrDig = minArr[j] - '0';
            short product = (maxArrCurrDig * minArrCurrDig) + carryIn;
            tmp1Num[tmp1Size++] = (product % 10) + '0';
            carryIn = product / 10;
        }
        if (carryIn > 0)
        {
            tmp1Num[tmp1Size++] = carryIn + '0';
        }

        reverseArr(tmp1Num, tmp1Size);
        for (unsigned k = 0; k < maxSize - i - 1; k++)
        {
            tmp1Num[tmp1Size++] = '0';
        }
        reverseArr(tmp1Num, tmp1Size);
        tmpResultSize = add(resultArr, tmp1Num, tmp2Num, tmp1Size, tmpResultSize);
        reverseArr(resultArr, tmpResultSize);
        formatArray(resultArr, tmpResultSize);
        reverseArr(resultArr, tmpResultSize);
        for (unsigned l = 0; l < tmpResultSize; l++)
        {
            tmp2Num[l] = resultArr[l];
        }
    }

    return tmpResultSize;
}

/**
 * Adds two numbers as character arrays together and prints them in the format
 * "first + second = result"
 * The result is saved in a new array.
 * If first is longer than second then the first number's end index will be 
 * bigger than the second's, so reversing them solves the problem since both
 * will start from index 0.
 * 
 * @param first first number as character array
 * @param second second number as character array
 * @param fstSize first array's size
 * @param sndSize second array's size
 */
void numbersAddition(char first[], char second[], unsigned fstSize, unsigned sndSize)
{
    unsigned resultSize = 0;
    reverseArr(first, fstSize);
    reverseArr(second, sndSize);

    if (fstSize >= sndSize)
    {
        resultSize = add(result, first, second, fstSize, sndSize);
    }
    else
    {
        resultSize = add(result, second, first, sndSize, fstSize);
    }

    reverseArr(first, fstSize);
    reverseArr(second, sndSize);

    reverseArr(result, resultSize);
    resultSize = formatArray(result, resultSize);

    printFormat(first, second, fstSize, sndSize, '+');
    cout << " = ";
    printArray(result, resultSize);
    clearArray(result, resultSize);
}

void numbersSubtraction(char first[], char second[], unsigned fstSize, unsigned sndSize)
{
    unsigned resultSize = 0;
    reverseArr(first, fstSize);
    reverseArr(second, sndSize);

    if (fstSize > sndSize)
    {
        resultSize = subtract(result, first, second, fstSize, sndSize);
    }
    else if (fstSize == sndSize)
    {
        switch (numberComparison(first, second, fstSize, sndSize))
        {
        case 0:
        case 1:
            resultSize = subtract(result, first, second, fstSize, sndSize);
            break;
        case -1:
            resultSize = subtract(result, second, first, sndSize, fstSize);
            break;
        }
    }
    else
    {
        resultSize = subtract(result, second, first, sndSize, fstSize);
    }

    reverseArr(first, fstSize);
    reverseArr(second, sndSize);

    reverseArr(result, resultSize);
    resultSize = formatArray(result, resultSize);

    printFormat(first, second, fstSize, sndSize, '-');
    cout << " = ";
    printArray(result, resultSize);
    clearArray(result, resultSize);
}

void numbersMultiplication(char first[], char second[], unsigned fstSize, unsigned sndSize)
{
    unsigned resultSize = 0;
    if (fstSize >= sndSize)
    {
        resultSize = multiply(result, first, second, fstSize, sndSize);
    }
    else
    {
        resultSize = multiply(result, second, first, sndSize, fstSize);
    }

    resultSize = formatArray(result, resultSize);
    reverseArr(result, resultSize);
    printFormat(first, second, fstSize, sndSize, '*');
    cout << " = ";
    printArray(result, resultSize);
    clearArray(result, resultSize);
}

int main()
{
    cin >> a;
    cin >> b;

    unsigned aSize = getSize(a);
    unsigned bSize = getSize(b);

    if (!isValid(a, aSize) || !isValid(b, bSize))
    {
        cout << "Not a valid number.";
        return 1;
    }

    aSize = formatArray(a, aSize);
    bSize = formatArray(b, bSize);

    // Compare the numbers
    int comparison = numberComparison(a, b, aSize, bSize);
    if (comparison == 0)
    {
        printFormat(a, b, aSize, bSize, '=');
    }
    else if (comparison == -1)
    {
        printFormat(a, b, aSize, bSize, '!');
        cout << endl;
        printFormat(a, b, aSize, bSize, '<');
    }
    else
    {
        printFormat(a, b, aSize, bSize, '!');
        cout << endl;
        printFormat(a, b, aSize, bSize, '>');
    }
    cout << endl;

    // Add b to a
    numbersAddition(a, b, aSize, bSize);
    cout << endl;

    // Subtract b from a
    numbersSubtraction(a, b, aSize, bSize);
    cout << endl;

    // Multiply a by b
    numbersMultiplication(a, b, aSize, bSize);
    cout << endl;

    return 0;
}