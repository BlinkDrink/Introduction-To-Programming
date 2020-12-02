#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

bool isPrime(unsigned n) {
//	cout << n << endl;

	if (n == 2) return true;
	if (n == 1 || n % 2 == 0) return false;

	unsigned lim = sqrt(n);
	for (unsigned i = 3; i <= lim; i++) {
		if (n % i == 0) return false;
	}

	return true;
}

int main() {
	unsigned n;
	cin >> n;

	while (n > 0) {
		if (!isPrime(n)) {
			cout << "false" << endl;
			return 0;
		}
		n /= 10;
	}

	cout << "true" << endl;
	return 0;
}