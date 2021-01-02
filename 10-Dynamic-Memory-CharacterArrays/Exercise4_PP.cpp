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

const char *find(const char *substr, const char *str)
{
    unsigned substrLen = len(substr);
    unsigned pos;
    const char *strEnd = str + len(str);

    while (str + substrLen <= strEnd)
    {
        for (pos = 0; pos < substrLen; pos++)
        {
            if (str[pos] != substr[pos])
            {
                break;
            }
        }

        if (!substr[pos])
            return str;
        ++str;
    }

    return str + substrLen;
}

int main()
{
    std::cout << find("More", "Sample Text kekW More Sampe Text") << std::endl; // kekW More Sampe Text
    return 0;
}