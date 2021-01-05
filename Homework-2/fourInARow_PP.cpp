#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const unsigned MAX_HEIGHT = 20;
const unsigned MAX_WIDTH = 40;
const unsigned WINNING_SEQUENCE_LENGTH = 4;

const char NO_ONE = 'N';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void clearBoard()
{
    system("cls");
}

unsigned readHeight()
{
    unsigned height;
    const unsigned MIN_HEIGHT_INPUT = 4;
    do
    {
        cin >> height;
    } while (height < MIN_HEIGHT_INPUT || height > MAX_HEIGHT || !cin);

    return height;
}

unsigned readWidth()
{
    unsigned width;
    const unsigned MIN_WIDTH_INPUT = 4;
    do
    {
        cin >> width;
    } while (width < MIN_WIDTH_INPUT || width > MAX_WIDTH || !cin);

    return width;
}

unsigned readCommand(unsigned width)
{
    unsigned command;
    do
    {
        cin >> command;
    } while (command < 1 || command > width || !cin);
    return command;
}

void initializeBoard(char board[][MAX_WIDTH], unsigned height, unsigned width)
{
    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            board[i][j] = ' ';
        }
    }
}

bool isBoardFull(char board[][MAX_WIDTH], unsigned height, unsigned width)
{
    int row = 0;
    // Check if the top most row is full
    for (unsigned col = 0; col < width; col++)
    {
        if (board[row][col] == ' ')
        {
            return false;
        }
    }

    return true;
}

void showBoard(char board[][MAX_WIDTH], unsigned height, unsigned width)
{
    for (unsigned i = 0; i < height; i++)
    {
        for (unsigned j = 0; j < width; j++)
        {
            cout << '|' << board[i][j];
        }
        cout << '|';
        cout << endl;
    }
}

bool areFourInALine(char sequence[WINNING_SEQUENCE_LENGTH], char currentPlayer)
{
    for (unsigned i = 0; i < WINNING_SEQUENCE_LENGTH; i++)
    {
        if (sequence[i] != currentPlayer)
        {
            return false;
        }
    }
    return true;
}

int modifyBoard(char board[][MAX_WIDTH], unsigned command, unsigned height, unsigned width, char player)
{
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == command - 1)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = player;
                    return 0;
                }
            }
        }
    }
    return 1;
}

char winner(char board[][MAX_WIDTH], unsigned height, unsigned width, char currentPlayer)
{
    char winningPlayer = NO_ONE;
    char sequence[WINNING_SEQUENCE_LENGTH];

    // Checking rows
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = j; k < (WINNING_SEQUENCE_LENGTH + j) && (WINNING_SEQUENCE_LENGTH + j <= width); k++)
            {
                sequence[k - j] = board[i][k];
            }

            if (areFourInALine(sequence, currentPlayer))
            {
                winningPlayer = currentPlayer;
                return winningPlayer;
            }
        }
    }

    // Checking columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = j; (k < WINNING_SEQUENCE_LENGTH + j) && (WINNING_SEQUENCE_LENGTH + j <= width); k++)
            {
                sequence[k - j] = board[k][i];
            }
            if (areFourInALine(sequence, currentPlayer))
            {
                winningPlayer = currentPlayer;
                return winningPlayer;
            }
        }
    }

    // Checking right down diagonals
    for (int i = 0; i <= height - WINNING_SEQUENCE_LENGTH; i++)
    {
        for (int j = 0; j <= width - WINNING_SEQUENCE_LENGTH; j++)
        {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3])
            {
                winningPlayer = board[i][j];
                return winningPlayer;
            }
        }
    }

    // Checking right up diagonals
    for (int i = WINNING_SEQUENCE_LENGTH - 1; i < height; i++)
    {
        for (int j = 0; j <= width - WINNING_SEQUENCE_LENGTH; j++)
        {
            if (board[i][j] != ' ' &&
                board[i][j] == board[i - 1][j + 1] &&
                board[i][j] == board[i - 2][j + 2] &&
                board[i][j] == board[i - 3][j + 3])
            {
                winningPlayer = board[i][j];
                return winningPlayer;
            }
        }
    }

    return winningPlayer;
}

int main()
{
    clearBoard();
    unsigned height, width;
    unsigned command;

    char board[MAX_HEIGHT][MAX_WIDTH];

    bool isPlayerO = true;
    char winningPlayer = NO_ONE;

    height = readHeight();
    width = readWidth();
    initializeBoard(board, height, width);
    showBoard(board, height, width);

    do
    {
        if (isPlayerO)
        {
            int status = 1;
            do
            {
                command = readCommand(width);
                status = modifyBoard(board, command, height, width, PLAYER_O);
            } while (status == 1);

            winningPlayer = winner(board, height, width, PLAYER_O);
            clearBoard();
            showBoard(board, height, width);
        }
        else
        {
            int status = 1;
            do
            {
                command = readCommand(width);
                status = modifyBoard(board, command, height, width, PLAYER_X);
            } while (status == 1);

            winningPlayer = winner(board, height, width, PLAYER_X);
            clearBoard();
            showBoard(board, height, width);
        }

        if (winningPlayer != NO_ONE || isBoardFull(board, height, width))
            break;

        isPlayerO = !isPlayerO;
    } while (winningPlayer == NO_ONE);

    cout << (winningPlayer != NO_ONE ? (winningPlayer == 'X' ? "Player 2 " : "Player 1 ") : "No one ") << "wins!";

    return 0;
}