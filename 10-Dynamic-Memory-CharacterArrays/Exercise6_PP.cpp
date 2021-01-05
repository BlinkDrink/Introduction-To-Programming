#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned max_size = 100;
const char visited = 'X';

bool readWordRec(char table[][max_size], unsigned size, const char *word, int currentRow, int currentCol)
{
    if (*word == '\0')
    {
        return true;
    }
    if (currentCol < 0 || currentCol >= size)
    {
        return false;
    }
    if (currentRow < 0 || currentRow >= size)
    {
        return false;
    }
    if (table[currentRow][currentCol] == visited)
    {
        return false;
    }
    if (table[currentRow][currentCol] != *word)
    {
        word--;
        return false;
    }

    table[currentRow][currentCol] = visited;

    return readWordRec(table, size, word + 1, currentRow + 1, currentCol - 1) ||
           readWordRec(table, size, word + 1, currentRow - 1, currentCol - 1) ||
           readWordRec(table, size, word + 1, currentRow - 1, currentCol + 1) ||
           readWordRec(table, size, word + 1, currentRow + 1, currentCol + 1);
}

bool can_read_word(char table[max_size][max_size], unsigned size, const char *word)
{
    char startLetter = '\0';
    bool isPossible = false;
    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned j = 0; j < size; j++)
        {
            if (table[i][j] == *word)
            {
                isPossible = readWordRec(table, size, word, i, j);
                if (isPossible)
                    return true;
            }
        }
    }

    return isPossible;
}

main()
{
    char table[max_size][max_size]{
        {'a', 'p', 'p', 'd'},
        {'k', 'a', 'x', 'p'},
        {'c', 'a', 'a', 'p'},
        {'a', 'k', 'e', 'r'},
    };

    cout << std::boolalpha << can_read_word(table, 4, "kappa") << '\n';
    // true, start at [3,1] and go up-right, up-right, up-left, down-left
    return 0;
}