#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
	long n, m;
	cin >> n >> m;

	if (n < 0 || m < 0 || (n - m) >= 0) {
		cout << 0 << endl;
		return 0;
	}

	int c = 0;
	for (int i = n; i < m; i++) {

		unsigned sum = 0;
		unsigned product = 1;

		for (int j = i; j > 0; j = j / 10) {
			short digit = j % 10;
			if (digit == 0) break;
			sum += digit;
			product *= digit;
		}

		c += (product == sum);
	}
	cout << c << endl;
	return 0;
}