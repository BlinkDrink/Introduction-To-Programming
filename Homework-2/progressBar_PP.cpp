#include <iostream>
#include <chrono>
#include <thread>

using std::cin;
using std::cout;
using std::endl;

using std::chrono::milliseconds;
using std::this_thread::sleep_for;

const unsigned MAX_SIZE = 100;
const double ONE_SECOND = 1000.0; // In ms
char bar[MAX_SIZE];
const char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Used in initializeBar() to obtain char of digit

/**
 * Using \b symbols to delete the bar. System("cls") is a slower operation than \b.
 * 
 * @param length length of the bar
 */
void clearScreen(unsigned length)
{
    for (unsigned i = 0; i < length; i++)
    {
        cout << "\b \b";
    }
}

/**
 * Function to initialize the bar with the given characters.
 * Escapes the need to reinitialize the remaining empty symbols
 * Takes default parameters.
 */
void initializeProgressBar(unsigned length, char leftClosingSymbol = '<', char rightClosingSymbol = '>', char fillingSymbol = '*', char emptySymbol = ' ')
{
    bar[0] = leftClosingSymbol;
    bar[length - 1] = rightClosingSymbol;

    for (unsigned i = 1; i < length - 1; i++)
    {
        bar[i] = emptySymbol;
    }
}

/**
 * Function to update and print progress bar iteration.
 * 
 * @param currentProgress Number in [0,1] denoting the bar's completition
 * @param length bar's length
 */
void printProgressBar(double currentProgress, unsigned length, char leftClosingSymbol = '<', char rightClosingSymbol = '>', bool showPercentage = false, char fillingSymbol = '*', char emptySymbol = ' ')
{
    unsigned fillUntilIndex = currentProgress * length;

    for (unsigned i = 1; i <= fillUntilIndex; i++)
    {
        if (i == length - 1)
        {
            currentProgress = 1;
        }

        bar[i] = fillingSymbol;

        if (showPercentage)
        {
            const char percentageSymbol = '%';
            const unsigned middleIndex = length / 2;
            unsigned percentageToInt = (int)(currentProgress * 100);
            unsigned firstDigit = (percentageToInt / 10) % 10;
            unsigned secondDigit = percentageToInt % 10;

            if (currentProgress >= 1.0)
            {
                bar[middleIndex - 2] = percentageSymbol;
                bar[middleIndex - 1] = '1';
                bar[middleIndex] = '0';
                bar[middleIndex + 1] = '0';
            }
            else
            {
                bar[middleIndex - 1] = percentageSymbol;
                bar[middleIndex] = percentageToInt < 10 ? '0' : digits[firstDigit];
                bar[middleIndex + 1] = digits[secondDigit];
            }
        }
    }

    bar[length - 1] = rightClosingSymbol;
    for (unsigned i = 0; i < length; i++)
    {
        cout << bar[i];
    }
}

int main()
{
    unsigned seconds;
    do
    {
        cin >> seconds;
    } while (seconds < 1);

    // The function takes default parameters as well if none are given
    const char leftClosingSymbol = '[';
    const char rightClosingSymbol = ']';
    const char bodyFiller = '-';
    const char bodyEmpty = ' ';

    unsigned length = 25;
    double currentProgress = 0;
    bool showPercentage = true;

    // Calculating how many times the bar will be redsiplayed in 1 second to simulate smooth effect
    unsigned refreshRate = 10;
    unsigned pauseTime = (ONE_SECOND / refreshRate);
    unsigned totalCount = refreshRate * seconds;
    double progressPerRefresh = 1.0 / totalCount;

    initializeProgressBar(length, leftClosingSymbol, rightClosingSymbol, bodyFiller, bodyEmpty);

    for (unsigned i = 0; i < totalCount; i++)
    {
        clearScreen(length);
        currentProgress += progressPerRefresh;
        printProgressBar(currentProgress, length, leftClosingSymbol, rightClosingSymbol, showPercentage, bodyFiller, bodyEmpty);
        sleep_for(milliseconds(pauseTime));
    }

    return 0;
}
