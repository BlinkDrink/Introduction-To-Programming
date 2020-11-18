#include <iostream>
using namespace std;

/*
Да се напише функция която по дадено n пресмята n!. n! = n*(n - 1)*(n - 2)*...*3*2*1.
Сигнатура на функцията:

long long fact(int n)
*/

long long fact(int n) {
	if (n < 0) return -1;
	return n > 1 ? n * fact(n-1) : 1;
}

int main() {
	unsigned int n;
	cin >> n;

	cout << fact(n);
}