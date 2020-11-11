#include <iostream>
#include <cmath>
using namespace std;

/*
Напишете програма, която въвежда от клавиатурата цeлите числа m и n (m < n).
Програмата да извежда броя на числата в интервала [m, n], сумата от цифрите, на които, е просто число.
Използвайте Функцията от предишната задача за проверка.
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
	unsigned int m, n;
	cin >> m >> n;
	if (m >= n) return -1;
	for (int i = m; i <= n; i++) {
		if (sumOfDigitsIsPrime(i)) cout << i << ' ';
	}
	cout << endl;
	return 0;
}