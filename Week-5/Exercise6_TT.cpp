#include <iostream>
#include <cmath>
using namespace std;

/*
Напишете булева функция, която приема цяло, положително число n и връща
true ако сумата от цифрите на n е просто число, false в противен случай. Сигнатура на функцията:

bool sumOfDigitsIsPrime(int n)
*/

bool isPrime(int n) {
	if (!(n & 1)) return false;
	int lim = sqrt(n);
	for (int i = 3; i <= lim; i += 2) {
		if (n % i) continue;
		else return false;
	}
}

bool sumOfDigitsIsPrime(int n) {
	unsigned int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return isPrime(sum);
}

int main() {
	unsigned int i;
	cin >> i;
	cout << (sumOfDigitsIsPrime(i) ? "T" : "F");
}