#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool hasPathRec(char path[][6], unsigned rows, unsigned cols, unsigned fstPosRow,
                unsigned fstPosCol, unsigned sndPosRow, unsigned sndPosCol)
{
    if (fstPosRow >= rows || sndPosRow >= rows || fstPosCol >= cols || sndPosCol >= cols)
    {
        return false;
    }
    if (path[fstPosRow][fstPosCol] == '0' || path[sndPosRow][sndPosCol] == '0')
    {
        return false;
    }
    if (fstPosRow == sndPosRow && fstPosCol == sndPosCol)
    {
        return true;
    }

    path[fstPosRow][fstPosCol] = '0';

    return hasPathRec(path, rows, cols, fstPosRow + 1, fstPosCol, sndPosRow, sndPosCol) ||
           hasPathRec(path, rows, cols, fstPosRow - 1, fstPosCol, sndPosRow, sndPosCol) ||
           hasPathRec(path, rows, cols, fstPosRow, fstPosCol + 1, sndPosRow, sndPosCol) ||
           hasPathRec(path, rows, cols, fstPosRow, fstPosCol - 1, sndPosRow, sndPosCol);
}

int main()
{
    const unsigned ROWS = 4;
    const unsigned COLS = 6;
    char path[ROWS][COLS] =
        {{'1', '0', '0', '0', '0', '1'},
         {'1', '1', '1', '0', '0', '0'},
         {'0', '0', '1', '0', '0', '0'},
         {'0', '0', '1', '1', '1', '1'}};

    unsigned short fstPosRow, fstPosCol, sndPosRow, sndPosCol;

    cin >> fstPosRow >> fstPosCol >> sndPosRow >> sndPosCol;

    cout << hasPathRec(path, ROWS, COLS, fstPosRow, fstPosCol, sndPosRow, sndPosCol);

    return 0;
}