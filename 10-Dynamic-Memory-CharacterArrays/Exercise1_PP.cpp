#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

bool isWordLetter(char letter)
{
    return (letter != ' ' && letter != '\0');
}

char *reverse_words(char *str)
{
    char *pHelper = str;
    char *pResult = str;

    while (*str)
    {
        while (isWordLetter(*str))
        {
            str++;
        }

        str--;

        while (str > pHelper)
        {
            swap(*str, *pHelper);
            str--;
            pHelper++;
        }

        while (isWordLetter(*str))
        {
            str++;
        }

        str++;
        pHelper = str;
    }

    return pResult;
}

int main()
{
    char sentence[100];
    cin.getline(sentence, 100);
    std::cout << reverse_words(sentence); // nruT taht nworf edispu nwod (:
    return 0;
}