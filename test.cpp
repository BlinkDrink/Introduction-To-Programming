#include <iostream>
#include <cstring>
using namespace std;

int length(int number)
{
    if (number >= 0 && number <= 9)
    {
        return 1;
    }
    return length(number / 10) + 1;
}

//a^b
int pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * pow(a, b - 1);
}

char *intToString(int number)
{
    int numLength = length(number);
    char *string = new (nothrow) char[numLength + 1];
    if (string == nullptr)
    {
        return nullptr;
    }
    cout << "Success" << endl;
    for (int i = 0; i < numLength; i++)
    {
        int currentDigit = number % 10;
        string[numLength - i - 1] = '0' + currentDigit;
        number /= 10;
    }
    string[numLength] = 0;
    return string;
}

char *rleEncode(const char *text)
{
    int textLen = strlen(text);
    char *result = new char[textLen + 1];
    int resultIndex = 0;
    for (int i = 0; i < textLen;)
    {
        if (i < textLen - 3 && text[i] == text[i + 1] && text[i] == text[i + 2] &&
            text[i] == text[i + 3])
        {
            //TODO
            int occurences = 0;
            for (int j = i; text[j] == text[i]; j++, occurences++)
            {
            }

            result[resultIndex] = '(';
            resultIndex++;

            char *occurencesString = intToString(occurences);
            if (occurencesString == nullptr)
            {
                return nullptr;
            }
            for (int j = 0; j < strlen(occurencesString); j++)
            {
                result[resultIndex] = occurencesString[j];
                resultIndex++;
            }
            delete[] occurencesString;

            result[resultIndex] = text[i];
            resultIndex++;
            result[resultIndex] = ')';
            resultIndex++;

            i += occurences;
        }
        else
        {
            result[resultIndex] = text[i];
            resultIndex++;

            i++;
        }
    }
    result[resultIndex] = 0;
    return result;
}

int main()
{
    char str[64];
    cin >> str;
    cout << rleEncode(str) << endl;
    return 0;
}