#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int invalidData() {
	cout << "Invalid date/time" << endl;
	return -1;
}

bool isLeap(unsigned short year) {
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

unsigned short getDaysUntil(unsigned short day, unsigned short month, unsigned short year) {
	unsigned short days = day;
	month--;
	switch (month) {
		case 12: /* unreachable */
			days += 31;
		case 11:
			days += 30;
		case 10:
			days += 31;
		case 9:
			days += 30;
		case 8:
			days += 31;
		case 7:
			days += 31;
		case 6:
			days += 30;
		case 5:
			days += 31;
		case 4:
			days += 30;
		case 3:
			days += 31;
		case 2:
			days += isLeap(year) ? 29 : 28;
		case 1:
			days += 31;
	}
//	cout << days << endl;
	return days;
}

unsigned short getDaysInMonth(unsigned short month, unsigned short year) {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;

		case 4:
		case 6:
		case 9:
		case 11:
			return 30;

		case 2:
			return isLeap(year) ? 29 : 28;

		default: {
			return -1;
		}
	}
}

bool isValid(unsigned short day1, unsigned short mon1, unsigned short yr1,
			 unsigned short hr1, unsigned short min1, unsigned short sec1) {

	if (mon1 == 0 || mon1 > 12) return false;
	if (day1 == 0 || day1 > getDaysInMonth(mon1, yr1)) return false;
	if (hr1 >= 24 || min1 >= 60 || sec1 >= 60) return false;

	return true;
}

short isAfter(unsigned short day1, unsigned short mon1, unsigned short yr1,
			  unsigned short hr1, unsigned short min1, unsigned short sec1,
			  unsigned short day2, unsigned short mon2, unsigned short yr2,
			  unsigned short hr2, unsigned short min2, unsigned short sec2) {

	if (yr1 > yr2) return 1;
	if (yr1 < yr2) return -1;

	unsigned short gdu1 = getDaysUntil(day1, mon1, yr1);
	unsigned short gdu2 = getDaysUntil(day2, mon2, yr2);

	if (gdu1 > gdu2) return 1;
	if (gdu1 < gdu2) return -1;

	unsigned int secs1 = 60 * 60 * hr1 + 60 * min1 + sec1;
	unsigned int secs2 = 60 * 60 * hr2 + 60 * min2 + sec2;

	return secs1 > secs2 ? 1 : (secs1 < secs2 ? -1 : 0);
}

unsigned short floorLeap(unsigned short year) {
	if (isLeap(year)) return year;
	if (year % 100 == 0) return year - 4;

	int rem = year % 4;
	if (isLeap(year - rem)) return year - rem;
	return year - 4 - rem;
}

unsigned short leapYearsUntil(unsigned short year) {
	short result = 0;
	if (isLeap(year)) result--;
	year = floorLeap(year);
	result += year/400 + year/4 - year/100;
	return result;
}

unsigned short normalYearsUntil(unsigned short year) {
	return year - 1 - leapYearsUntil(year); // -1 because we're starting from 1, not from 0
}

int main() {
	// Shared vars
	char delimiter1, delimiter2;

	// Datetime 1 vars
	unsigned short day1, mon1, yr1;
	unsigned short hr1, min1, sec1;

	// Input datetime 1
	cin >> day1 >> delimiter1 >> mon1 >> delimiter2 >> yr1;
	if (delimiter1 != '.' || delimiter2 != '.') return invalidData();
	cin >> hr1 >> delimiter1 >> min1 >> delimiter2 >> sec1;
	if (delimiter1 != ':' || delimiter2 != ':') return invalidData();
	if (!isValid(day1, mon1, yr1, hr1, min1, sec1)) return invalidData();

	// Datetime 2 vars
	unsigned short day2, mon2, yr2;
	unsigned short hr2, min2, sec2;

	// Input datetime 1
	cin >> day2 >> delimiter1 >> mon2 >> delimiter2 >> yr2;
	if (delimiter1 != '.' || delimiter2 != '.') return invalidData();
	cin >> hr2 >> delimiter1 >> min2 >> delimiter2 >> sec2;
	if (delimiter1 != ':' || delimiter2 != ':') return invalidData();
	if (!isValid(day2, mon2, yr2, hr2, min2, sec2)) return invalidData();


	// Datetime 3 vars
	long long day3 = 0;
	short hr3 = 0, min3 = 0, sec3;

	short k = isAfter(day1, mon1, yr1, hr1, min1, sec1, day2, mon2, yr2, hr2, min2, sec2);
	if (k == 0) cout << "00:00:00" << endl;

	// Debug info
//	cout << day1 << '.' << mon1 << '.' << yr1 << ' ' << hr1 << ':' << min1 << ':' << sec1 << endl;
//	cout << day2 << '.' << mon2 << '.' << yr2 << ' ' << hr2 << ':' << min2 << ':' << sec2 << endl;

	sec3 = k * (sec1 - sec2);
	if (sec3 < 0) {
		sec3 += 60;
		min3 -= 1;
	}
	min3 += k * (min1 - min2);
	if (min3 < 0) {
		min3 += 60;
		hr3 -= 1;
	}
	hr3 += k * (hr1 - hr2);
	if (hr3 < 0) {
		hr3 += 24;
		day3 -= 1;
	}

	day3 += k * (getDaysUntil(day1, mon1, yr1) - getDaysUntil(day2, mon2, yr2));

	unsigned short leapYears = k * (leapYearsUntil(yr1) - leapYearsUntil(yr2));
//	cout << leapYears << " Leap years" << endl;

	unsigned short normalYears = k * (normalYearsUntil(yr1) - normalYearsUntil(yr2));
//	cout << normalYears << " Normal years" << endl;

	day3 += normalYears * 365;
	day3 += leapYears * 366;

	if (day3 != 0) cout << day3 << '-';

	if (hr3 < 10) cout << '0';
	cout << hr3 << ':';

	if (min3 < 10) cout << '0';
	cout << min3 << ':';

	if (sec3 < 10) cout << '0';
	cout << sec3;

	return 0;
}