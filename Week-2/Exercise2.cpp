#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/*
Да се напише програма, която по въвени години(цяло число) да пресмята 
на колко седмици, дни, часове, минути и секунди се равняват.
*/

int main()
{
    int years;
    cin >> years;

    int leapYears = years / 4;
    int days = (years * 365) + leapYears;
    int weeks = days / 7;
    int hours = days * 24;
    int minutes = hours * 60;
    int seconds = minutes * 60;

    cout << "Weeks: " << weeks << endl
         << "Days: " << days << endl
         << "Hours: " << hours << endl
         << "Minutes: " << minutes << endl
         << "Seconds: " << seconds;

    return 0;
}
