#include <iostream>
using namespace std;

long long fact(int n) {
	if (n < 0) return -1;
	return n > 1 ? n * fact(n-1) : 1;
}

int main() {
	unsigned int n;
	cin >> n;

	cout << fact(n);
}