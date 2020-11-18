#include <iostream>
using namespace std;

/*
*Задача 5
Да се изведат първите 20 естествени числа, двоичния запис на които съдържа равен брой 0 и 1.
*/
bool isEligible(unsigned int i) {
//	if (i == 0) return false;

	unsigned int oneCount = 0;
	unsigned int zeroCount = 0;

	while (i > 0) {
		i & 1 ? oneCount++ : zeroCount++;
		i >>= 1;
	}
	return oneCount == zeroCount;
}

int main() {
	unsigned int n;
	unsigned int curr = 0;
	cin >> n;

	int i = 1;
	while (curr < n) {
		if (isEligible(i)) {
			cout << i << ' ';
			curr++;
		}
		i++;
	}
	return 0;
}