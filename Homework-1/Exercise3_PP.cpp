#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int daysInAMonth(int month, bool isLeap)
{
    int days = 0;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        days = isLeap ? 29 : 28;
        break;
    default:
        days = 0;
        break;
    }

    return days;
}

int daysUpToAGivenMonth(int month, bool isLeap)
{
    int days = 0;

    days += 31;
    if (month == 1)
    {
        return days;
    }
    days += isLeap ? 29 : 28;
    if (month == 2)
    {
        return days;
    }
    days += 31;
    if (month == 3)
    {
        return days;
    }
    days += 30;
    if (month == 4)
    {
        return days;
    }
    days += 31;
    if (month == 5)
    {
        return days;
    }
    days += 30;
    if (month == 6)
    {
        return days;
    }
    days += 31;
    if (month == 7)
    {
        return days;
    }
    days += 31;
    if (month == 8)
    {
        return days;
    }
    days += 30;
    if (month == 9)
    {
        return days;
    }
    days += 31;
    if (month == 10)
    {
        return days;
    }
    days += 30;
    if (month == 11)
    {
        return days;
    }
    days += 31;

    return (month < 1 || month > 12) ? 0 : days;
}

bool isDateValid(int days, int month, int year, bool isLeap, int hours, int minutes, int seconds)
{
    int daysInMonth = daysInAMonth(month, isLeap);

    if (hours > 23 || hours < 0 || minutes > 59 || minutes < 0 || seconds > 59 || seconds < 0)
    {
        return false;
    }
    else if (daysInMonth == 0)
    {
        return false;
    }
    else if (year < 0 || year > 9999)
    {
        return false;
    }
    else if (days > daysInMonth || days < 1)
    {
        return false;
    }

    return true;
}

long long absoluteValue(long long a)
{
    return a > 0 ? a : -a;
}

int main()
{
    char ch;
    int days1, month1, year1, hrs1, min1, sec1;
    int days2, month2, year2, hrs2, min2, sec2;

    cin >> days1 >> ch >> month1 >> ch >> year1 >> hrs1 >> ch >> min1 >> ch >> sec1;
    cin >> days2 >> ch >> month2 >> ch >> year2 >> hrs2 >> ch >> min2 >> ch >> sec2;

    bool y1IsLeapYear = ((year1 % 4 == 0) && (year1 % 100 != 0)) || (year1 % 400 == 0);
    bool y2IsLeapYear = ((year2 % 4 == 0) && (year2 % 100 != 0)) || (year2 % 400 == 0);

    if (!isDateValid(days1, month1, year1, y1IsLeapYear, hrs1, min1, sec1) ||
        !isDateValid(days2, month2, year2, y2IsLeapYear, hrs2, min2, sec2) || !cin)
    {
        cout << "Invalid date/time";
        return 1;
    }

    /* time1InDays is the sum of all years from 01.01.0001 to the currentYear - 1. Then summed with the days from
     01.01.{currentYear} to the current month-1. Then summed with currentDays.Then summed with all leapYears from 
     01.01.0001 to current year. From the result I then remove 1 because the last day shouldn't be included. 
    */

    //01.02.04 00:00:00 01.01.05 00:00:00
    unsigned time1HoursToSeconds = (hrs1 * 3600) + (min1 * 60) + sec1;
    unsigned time1LeapYearsCount = (((year1 - 1) / 4) - ((year1 - 1) / 100) + ((year1 - 1) / 400));
    unsigned time1YearsInDays = year1 * 365;
    unsigned time1DaysOfCurrentYear = daysUpToAGivenMonth(month1 - 1, y1IsLeapYear);
    long long time1InDays = days1 + time1YearsInDays + time1DaysOfCurrentYear + time1LeapYearsCount;
    long long time1InSeconds = (time1InDays * 24 * 3600) + time1HoursToSeconds;

    unsigned time2HoursToSeconds = (hrs2 * 3600) + (min2 * 60) + sec2;
    unsigned time2LeapYearsCount = (((year2 - 1) / 4) - ((year2 - 1) / 100) + ((year2 - 1) / 400));
    unsigned time2YearsInDays = year2 * 365;
    unsigned time2DaysOfCurrentYear = daysUpToAGivenMonth(month2 - 1, y2IsLeapYear);
    long long time2InDays = days2 + time2YearsInDays + time2DaysOfCurrentYear + time2LeapYearsCount;
    long long time2InSeconds = (time2InDays * 24 * 3600) + time2HoursToSeconds;

    long long secondsDifference = absoluteValue(time1InSeconds - time2InSeconds);

    unsigned secondsDiffInDays = secondsDifference / (24 * 3600);

    secondsDifference = secondsDifference % (24 * 3600);
    unsigned secondsDiffInHours = secondsDifference / 3600;

    secondsDifference %= 3600;
    unsigned secondsDiffInMinutes = secondsDifference / 60;

    secondsDifference %= 60;
    unsigned secondsDiffInSeconds = secondsDifference;

    if (secondsDiffInDays > 0)
    {
        cout << secondsDiffInDays << "-";
    }
    else
    {
        cout << "";
    }

    if (secondsDiffInHours < 10)
    {
        cout << "0";
    }
    cout << secondsDiffInHours << ":";

    if ((secondsDiffInMinutes % 60) < 10)
    {
        cout << "0";
    }

    cout << (secondsDiffInMinutes % 60) << ":";

    if (secondsDiffInSeconds < 10)
    {
        cout << "0";
    }

    cout << secondsDiffInSeconds;

    return 0;
}