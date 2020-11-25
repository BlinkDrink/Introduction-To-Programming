#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isValid(unsigned hours, unsigned minutes, unsigned hourType)
{
    if (hourType == 1)
    {
        return ((hours > 23) || (minutes > 59)) ? false : true;
    }
    else
    {
        return ((hours > 13) || (hours < 1) || (minutes > 59)) ? false : true;
    }
}

int absoluteValue(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    unsigned t1, t2;
    cin >> t1 >> t2;

    if (!cin)
    {
        cout << "Invalid time!";
        return 1;
    }

    const unsigned MINUTES_MASK = (1 << 6) - 1; // Binary representation of 63(0011 1111)
    const unsigned HOUR_TYPE_MASK = (1 << 12);  // hourTypeMask check what kind of time system it is (12 or 24)
    const unsigned FIRST_DIGIT_OF_HOUR_MASK = ((1 << 4) - 1) << 6;
    const unsigned SECOND_DIGIT_OF_HOUR_MASK = ((1 << 2) - 1) << 10;

    unsigned t1Minutes = (t1 & MINUTES_MASK);
    unsigned t1FirstDigitOfHour = 10 * ((t1 & SECOND_DIGIT_OF_HOUR_MASK) >> 10);
    unsigned t1SecondDigitOfHour = ((t1 & FIRST_DIGIT_OF_HOUR_MASK) >> 6);
    unsigned t1Hours = t1FirstDigitOfHour + t1SecondDigitOfHour;
    unsigned t1HourType = (t1 & HOUR_TYPE_MASK) >> 12;

    unsigned t2Minutes = (t2 & MINUTES_MASK);
    unsigned t2FirstDigitOfHour = 10 * ((t2 & SECOND_DIGIT_OF_HOUR_MASK) >> 10);
    unsigned t2SecondDigitOfHour = ((t2 & FIRST_DIGIT_OF_HOUR_MASK) >> 6);
    unsigned t2Hours = t2FirstDigitOfHour + t2SecondDigitOfHour;
    unsigned t2HourType = (t2 & HOUR_TYPE_MASK) >> 12;

    if (!isValid(t1Hours, t1Minutes, t1HourType) || !isValid(t2Hours, t2Minutes, t2HourType))
    {
        cout << "Invalid time!";
        return 1;
    }

    cout << t1Hours << ":" << t1Minutes << endl;
    cout << t2Hours << ":" << t2Minutes << endl;

    if (t1Hours == 12 && t1HourType == 0)
        t1Hours = 0; // Doing this because when hour format is AM and PM we dont have 00:00 as an hour.
    if (t2Hours == 12 && t2HourType == 0)
        t2Hours = 0;

    unsigned difference = absoluteValue(((t1Hours * 60) + t1Minutes) - ((t2Hours * 60) + t2Minutes));

    unsigned formatedHours = difference / 60;
    unsigned formatedMinutes = difference % 60;

    cout << "diff ";
    if (formatedHours < 10)
    {
        cout << "0";
    }
    cout << formatedHours << ":";
    if (formatedMinutes < 10)
    {
        cout << "0";
    }
    cout << formatedMinutes;

    return 0;
}