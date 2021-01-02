#include <iostream>

using std::cin;
using std::cout;
using std::endl;

unsigned len(const char *str)
{
    unsigned length = 0;
    while (*str++)
    {
        length++;
    }
    return length;
}

bool isPalindrome(const char *str)
{
    int l = 0;
    int r = len(str) - 1;

    while (r > l)
        if (str[l++] != str[r--])
            return false;

    return true;
}

int cyclical_palindrome(const char *str)
{
    size_t idx = 0;
    size_t pos = 0;

    char *reformed = new char[len(str) + 1];
    const char *pHelper = str;
    const char *pSecondHelper = str;

    const char *strStart = str;
    const char *strEnd = str + len(str);

    while (*str)
    {
        pos++;
        while (pHelper < strEnd)
        {
            reformed[idx++] = *pHelper++;
        }
        while (pSecondHelper < str)
        {
            reformed[idx++] = *pSecondHelper++;
        }

        reformed[idx] = '\0';

        if (isPalindrome(reformed))
        {
            return pos - 1;
        }

        pHelper = ++str;
        pSecondHelper = strStart;
        idx = 0;
    }

    delete[] reformed;

    return -1;
}

int main()
{
    std::cout << cyclical_palindrome("lebeddebelarabbara"); // -> 6

    /*
    Ако започнем да четем думата от 6-тия индекс получаваме
    az (края на думата, за това се връщаме в началото)
    obi4amma4iboza (остатъка от думата)
    azobi4amma4iboza е валиден палиндром.
    */
    return 0;
}