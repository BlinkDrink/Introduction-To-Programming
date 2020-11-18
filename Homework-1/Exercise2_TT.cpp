#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Returns |a-b|
long long absDiff(long long a, long long b) {
	return (a > b ? a - b : b - a);
}

// Returns whether "i" is in [minValue, maxValue]
bool inRange(long long i, long long minValue, long long maxValue) {
	return (i >= minValue && i <= maxValue);
}

// Sources:
// https://en.wikipedia.org/wiki/12-hour_clock
// https://en.wikipedia.org/wiki/24-hour_clock
bool isValid(bool using12Hour, long long hour, long long min) {

	// Invalid 12h format: Hour must be between 1 and 12, inclusive
	// Wikipedia: "Each period consists of 12 hours numbered:
	//             12 (acting as zero), 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 and 11"
	if (using12Hour && !inRange(hour, 1, 12)) {
		cout << "Invalid data" << '\n'
			 << "Hour is not between 1 and 12 (both incl.) while using 12h format" << '\n'
			 << "hour = " << hour << endl;
		return false;
	}

	// Invalid 24h format: Hour must be between 0 and 23, inclusive
	// Wikipedia: "...This is indicated by the hours passed since midnight, from 0 to 23.
	//             This system is the most commonly used time notation in the world today..."
	if (!using12Hour && !inRange(hour, 0, 23)) {
		cout << "Invalid data" << '\n'
			 << "Hour is not between 0 and 23 (both incl.) while using 24h format" << '\n'
			 << "hour = " << hour << endl;
		return false;
	}

	if (!inRange(min, 0, 59)) {
		cout << "Invalid data" << '\n'
			 << "Minute is not between 0 and 59 (both incl.)" << '\n'
			 << "minute = " << min << endl;
		return false;
	}

	return true;
}

// Bitwise shift to the right by "shift" amount, select rightmost "mask" bits in that number
long long shiftAndMask(long long i, unsigned short shift, unsigned short mask) {
	return (i >> shift) & ((1 << mask) - 1);
}

int main() {
	// Below value is used for detecting whether the number is above 13 bits
	// 1 1111 1111 1111 in binary, 8191 in decimal
	const unsigned short MAX_13_BIT = (1 << 13) - 1;

	unsigned long long a;
	cin >> a;
	if (!inRange(a, 0, MAX_13_BIT)) {
		cout << "Invalid data" << '\n' <<
			 "Initial input has above 13 bits" << endl;
		return -1;
	}

	unsigned short a_min         =  shiftAndMask(a, 0, 6);
	unsigned short a_hour_1      =  shiftAndMask(a, 6, 4);
	unsigned short a_hour_2      =  shiftAndMask(a, 10, 2);
	bool           a_using12Hour = !shiftAndMask(a, 12, 1); // Always 0 or 1, mask length is 1
	unsigned short a_hour        =  10 * a_hour_2 + a_hour_1;

	if (!isValid(a_using12Hour, a_hour, a_min)) {
		return -1;
	}

	// Check case when:
	// 12:01 am = 00:01
	// 12:XY am = 00:XY
	// This change is only for calculating the difference
	if (a_using12Hour && a_hour == 12) a_hour = 0;


	unsigned long long b;
	cin >> b;
	if (!inRange(b, 0, MAX_13_BIT)) {
		cout << "Invalid data" << '\n' <<
			 "Initial input has above 13 bits" << endl;
		return -1;
	}

	unsigned short b_min         =  shiftAndMask(b, 0, 6);
	unsigned short b_hour_1      =  shiftAndMask(b, 6, 4);
	unsigned short b_hour_2      =  shiftAndMask(b, 10, 2);
	bool           b_using12Hour = !shiftAndMask(b, 12, 1); // Always 0 or 1, mask length is 1
	unsigned short b_hour        =  10 * b_hour_2 + b_hour_1;

	if (!isValid(b_using12Hour, b_hour, b_min)) {
		return -1;
	}

	// 12h format check
	if (b_using12Hour && b_hour == 12) b_hour = 0;


	// Actual difference calculation is the 2 lines below
	unsigned short diff_hour = absDiff(a_hour, b_hour);
	unsigned short diff_min  = absDiff(a_min, b_min);

	// Return hours to the way the user submitted them, if changed beforehand
	if (a_using12Hour && a_hour == 0) a_hour = 12;
	if (b_using12Hour && b_hour == 0) b_hour = 12;

	cout << a_hour << ':' << a_min << '\n'
		 << b_hour << ':' << b_min << '\n'
		 << "diff " << diff_hour << ':' << (diff_min < 10 ? "0" : "") << diff_min << endl;

	return 0;
}