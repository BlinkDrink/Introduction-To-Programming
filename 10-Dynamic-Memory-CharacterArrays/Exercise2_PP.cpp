#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isDigit(char letter)
{
    return (letter >= '0' && letter <= '9');
}

int atoi(char *str)
{
    int result = 0;
    bool isNegative = false;

    if (*str == '-')
    {
        isNegative = true;
        str++;
    }

    while (isDigit(*str))
    {
        result = (result * 10) + (*str - '0');
    }

    return isNegative ? -result : result;
}

int main()
{
    std::cout << atoi("23filler") + atoi("-81morefiller") << '\n'; // 42
    return 0;
}