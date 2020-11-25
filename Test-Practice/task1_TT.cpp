#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	double ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;

	// Construct a linear function passing through A and B
	// If A == B, it's always true, 2 points define a line
	// Else, check if C is on AB
	//
	// p*x + q = y
	//
	// ax*p + q = ay
	// bx*p + q = by
	// 1-2
	//
	// p(ax-bx) = ay-by
	// p = (ay-by)/(ax-bx)
	//
	// q = ay-ax*p
	//
	// cx*p + q = cy

	if (ax - bx == 0 && ay - by == 0) {
		cout << true << endl;
		return 0;
	}
	double p = (ay-by)/(ax-bx);
	double q = ay - ax*p;
	cout << (cx*p + q == cy) << endl;

	return 0;
}