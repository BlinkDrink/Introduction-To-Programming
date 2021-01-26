#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
using std::swap;

//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Контролно 2
// 2021-01-17
//
// Име: Петко Иванов Петков
// ФН: 45811
// Специалност: Информатика
// Курс: 1
// Административна група: 5
// Използван компилатор: mingw-64
//

void stringCopy(char **wordsTable, unsigned targetRow, char *words)
{
    unsigned currIndex = 0;
    while (*words != '\0')
    {
        wordsTable[targetRow][currIndex] = *words;
        currIndex++;
        words++;
    }
    wordsTable[targetRow][currIndex] = '\0';
}

bool isLetter(char symbol)
{
    return ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'));
}

void replaceCurrentWord(char *word, char *text)
{
    while (*word)
    {
        *text = *word;
        text++;
        word++;
    }
}

void checkIfInDictionary(char **wordsTable, unsigned tableRows, char *text)
{
    char *pText = text;
    bool isInDict = true;
    for (size_t i = 0; i < tableRows; i++)
    {
        char *pWords = wordsTable[i];
        char *pHelperWords = pWords;
        while (*pWords && !isLetter(*pWords))
        {
            pWords++;
        }

        if (*pWords && isLetter(*pWords))
        {
            while (*pText && *pWords)
            {
                if (*pText == *pWords)
                {
                    pText++;
                    pWords++;
                }
                else
                {
                    isInDict = false;
                    break;
                }
            }
            if (isInDict)
            {
                replaceCurrentWord(pHelperWords, text);
            }

            while (*pWords && !isLetter(*pWords))
            {
                pWords++;
            }
        }

        pText = text;
    }
}

void replaceWords(char **wordsTable, unsigned tableRows, char *text, unsigned textLen)
{
    while (*text)
    {
        while (*text && !isLetter(*text))
        {
            ++text;
        }
        if (*text && isLetter(*text))
        {
            checkIfInDictionary(wordsTable, tableRows, text);
        }
    }
}

int main()
{
    const unsigned MAX_WORDS_ON_ROW = 200;
    unsigned n, m;

    cin >> n;
    cin.ignore();

    char **wordsTable = new (nothrow) char *[n];

    for (size_t i = 0; i < n; i++)
    {
        wordsTable[i] = new (nothrow) char[MAX_WORDS_ON_ROW];
    }

    for (size_t i = 0; i < n; i++)
    {
        char *currentWords = new (nothrow) char[MAX_WORDS_ON_ROW];
        cin.getline(currentWords, MAX_WORDS_ON_ROW);

        stringCopy(wordsTable, i, currentWords);
        delete[] currentWords;
    }

    cin >> m;
    char *text = new (nothrow) char[m];

    cin.ignore();
    cin.getline(text, m);

    replaceWords(wordsTable, n, text, m);

    delete[] text;

    for (size_t i = 0; i < n; i++)
    {
        delete[] wordsTable[i];
    }
    delete[] wordsTable;

    return 0;
}
