#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isDigit(char letter)
{
    return (letter >= '0' && letter <= '9');
}

unsigned getCount(const char *str)
{
    unsigned cnt = 0;

    while (isDigit(*str))
    {
        cnt = (cnt * 10) + (*str - '0');
        str++;
    }

    return cnt;
}

unsigned getDigitCount(unsigned n)
{
    unsigned cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

char *run_length_decode(char *buffer, const char *str)
{
    int buffCnt = 0;
    while (*str)
    {
        if (isDigit(*str))
        {
            unsigned cnt = getCount(str);
            unsigned digitCnt = getDigitCount(cnt);

            for (unsigned i = 0; i < digitCnt; i++)
                str++;

            for (unsigned i = 0; i < cnt; i++)
                buffer[buffCnt++] = *str;
        }
        else
        {
            buffer[buffCnt++] = *str;
        }
        str++;
    }

    return buffer;
}

int main()
{
    char buffer[100]{};
    std::cout << run_length_decode(buffer, "4a2b10c"); // abbcccccccccc
    return 0;
}