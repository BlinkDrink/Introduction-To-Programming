#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
using std::swap;

bool readMatrix(unsigned **matrix, size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            cin >> matrix[i][j];

            if (!cin)
            {
                cout << "Invalid number";
                return false;
            }
        }
    }
    return true;
}

/**
 * This function gets the time:score coefficient used for comparing
 * task priority.
 * 
 * @param score the score awarded for completing the current task
 * @param time the time needed to complete the current task
 */
double getCmpCoef(unsigned score, unsigned time)
{
    return (double)time / (double)score;
}

void clearMatrixByRows(unsigned **matrix, size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

unsigned **matrixAllocation(size_t rows, size_t columns)
{
    unsigned **matrix = new (nothrow) unsigned *[rows];
    if (!matrix)
        return matrix;

    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new unsigned[columns];
        if (!matrix[i])
        {
            clearMatrixByRows(matrix, i);
            return nullptr;
        }
    }

    return matrix;
}

/**
 * This function is called right after sortByPriority to check
 * whether a better score can be achieved by rearranging the tasks'
 * order.
 * 
 * @param matrix the matrix - each row representing a task
 * @param rows tasks count
 * @param time total time given by the user
 */
void achieveMaxTasks(unsigned **matrix, size_t &rows, int time)
{
    unsigned maxScore = 0;
    for (size_t i = 0; i < rows; i++)
    {
        int timeForIteration = time;
        unsigned currMaxScore = 0;
        for (size_t j = i; j < rows; j++)
        {
            unsigned currScore = matrix[j][2];
            int currTime = matrix[j][1];
            if (timeForIteration - currTime >= 0)
            {
                timeForIteration -= currTime;
                currMaxScore += currScore;
            }
        }

        if (maxScore <= currMaxScore)
        {
            maxScore = currMaxScore;
            if (i > 0)
            {
                for (size_t o = i; o < rows; o++)
                {
                    swap(matrix[o - 1], matrix[o]);
                }

                rows--;
                i--;
            }
        }
    }
}

/**
 * This function sorts the tasks by priority.
 * Tasks with higher priority are those whoose time/score coefficient
 * is the lowest.
 * 
 * @param matrix the matrix - each row representing a task
 * @param rows tasks count
 * @param time total time given by the user
 */
void sortByPriority(unsigned **matrix, size_t rows, int time)
{
    int tmpTime = time;
    for (size_t i = 0; i < rows - 1; i++)
    {
        unsigned currTaskScore = matrix[i][2];
        int currTaskTime = matrix[i][1];
        double currCoef = getCmpCoef(currTaskScore, currTaskTime);

        for (size_t j = i + 1; j < rows; j++)
        {
            unsigned nextTaskScore = matrix[j][2];
            int nextTaskTime = matrix[j][1];
            double nextCoef = getCmpCoef(nextTaskScore, nextTaskTime);

            if (currCoef > nextCoef)
            {
                swap(matrix[i], matrix[j]);
            }
            else if (currCoef == nextCoef)
            {
                if (currTaskTime > nextTaskTime)
                {
                    swap(matrix[i], matrix[j]);
                }
                else if (currTaskTime == nextTaskTime)
                {
                    if (matrix[i][0] < matrix[j][0])
                    {
                        swap(matrix[i], matrix[j]);
                    }
                }
            }
        }
    }
    // Call this function here to check whether this sorted formation can achieve the best score.
    // If not - then rearange the tasks in such way that best score can be acheived.
    achieveMaxTasks(matrix, rows, tmpTime);
}

/**
 * This function is called during data input to take the time
 * for each day.
 * 
 * @param remainingDays days till the exam phase. Positive number
 * @param tasksTable matrix - each row representing a task
 * @param tasksCount the rows of the matrix(each row being a task)
 */
int getRemainingTime(unsigned remainingDays, unsigned **tasksTable, unsigned tasksCount)
{
    int totalTime = 0;
    int tmp = 0;

    for (size_t i = 0; i < remainingDays; i++)
    {
        cin >> tmp;
        if (!cin || tmp < 1)
        {
            cout << "Invalid number";

            return -1;
        }
        totalTime += tmp;
    }
    return totalTime;
}

/**
 *  Result formatting function.
 * 
 * @param matrix the matrix - each row representing a task
 * @param rows tasks count
 * @param time total time given by the user
 */
void showResult(unsigned **matrix, unsigned rows, int time)
{
    cout << "Tasks: ";
    cout << matrix[0][0];
    time -= matrix[0][1];
    for (size_t i = 1; i < rows; i++)
    {
        int currTaskTime = matrix[i][1];
        if (time - currTaskTime >= 0)
        {
            cout << ", " << matrix[i][0];
            time -= currTaskTime;
        }
    }
    cout << endl;

    unsigned hours = time / 60;
    unsigned minutes = time % 60;

    cout << "Time remaining: " << hours << ':' << minutes;
}

int main()
{
    unsigned tasksCount, remainingDays;
    int totalTime = 0;
    const unsigned numberOfDetails = 3;
    cin >> tasksCount;

    unsigned **tasksTable = matrixAllocation(tasksCount, numberOfDetails);
    if (!tasksTable)
        return 1;

    if (!readMatrix(tasksTable, tasksCount, numberOfDetails))
    {
        clearMatrixByRows(tasksTable, tasksCount);
        return 1;
    }

    cin >> remainingDays;

    totalTime = getRemainingTime(remainingDays, tasksTable, tasksCount);
    sortByPriority(tasksTable, tasksCount, totalTime);
    showResult(tasksTable, tasksCount, totalTime);

    clearMatrixByRows(tasksTable, tasksCount);
    return 0;
}