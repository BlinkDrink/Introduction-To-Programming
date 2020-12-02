#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	unsigned hi = 100;
	unsigned lo = 0;

	while (true) {

		if (hi == lo) {
			cout << hi << endl;
			break;
		}

		unsigned guess = (hi + lo) / 2;
		cout << "number > " << guess  << "?" << endl;

		bool ans;
		cin >> ans;

		if (hi - lo == 1) {
			cout << (ans ? hi : lo) << endl;
			break;
		}

		if (ans) {
			lo = guess + 1;
		}
		else {
			hi = guess;
		}

		cout << lo << "_" << hi << endl;
	}

	/**
	 * Unit test format below
	 */

//	for (int i = 1; i <= 100; i++) {
//
//
//		unsigned hi = 100;
//		unsigned lo = 0;
//
//		while (true) {
//
//			if (hi == lo) {
//				if (hi != i ) {
//					cout << "error at " << i << endl;
//				}
//				break;
//			}
//
//			unsigned guess = (hi + lo) / 2;
//
//			bool ans;
//			ans = i > guess;
//
//			if (hi - lo == 1) {
//				if ((ans ? hi : lo) != i ) {
//					cout << "error at " << i << endl;
//				}
//				break;
//			}
//
//			if (ans) {
//				lo = guess + 1;
//			}
//			else {
//				hi = guess;
//			}
//		}
//	}

	return 0;
}