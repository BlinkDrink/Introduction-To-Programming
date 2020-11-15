#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	double x1, y1, w1, h1;
	cin >> x1 >> y1 >> w1 >> h1;

	if (w1 <= 0 || h1 <= 0) {
		cout << "Invalid data" << endl;
		return -1;
	}

	double x2, y2, w2, h2;
	cin >> x2 >> y2 >> w2 >> h2;

	if (w2 <= 0 || h2 <= 0) {
		cout << "Invalid data" << endl;
		return -1;
	}

	// First get leftmost (lowest) x+w coord of either rectangle
	// Subtract that by the rightmost (greatest) x coord of either
	double x3 = ((x1 + w1) < (x2 + w2) ? (x1 + w1) : (x2 + w2)) - (x1 > x2 ? x1 : x2);

	// Get lowest y+h coord of either rectangle
	// Subtract that by the greatest y coord of either
	double y3 = ((y1 + h1) < (y2 + h2) ? (y1 + h1) : (y2 + h2)) - (y1 > y2 ? y1 : y2);

	double a = x3 * y3;

	cout << a << endl;

	return 0;
}