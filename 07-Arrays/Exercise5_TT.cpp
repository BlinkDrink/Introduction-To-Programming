#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void inputArray(int array[], int& length) {
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}
}

int getGreatestProduct(int *array, int& length) {
	int aPos = array[0];
	int bPos = array[1];
	// want: aPos > bPos
	if (aPos < bPos) swap(aPos, bPos);

	int aNeg = array[0];
	int bNeg = array[1];
	// want: aNeg < bNeg
	if (aNeg < bNeg) swap(aPos, bPos);

	for (int i = 2; i < length; i++) {
		if (array[i] > aPos) {
			bPos = aPos;
			aPos = array[i];
		}
		else if (array[i] > bPos) {
			bPos = array[i];
		}

		if (array[i] < aNeg) {
			bNeg = aNeg;
			aNeg = array[i];
		}
		else if (array[i] < bNeg) {
			bNeg = array[i];
		}
	}

	int maxNeg = aNeg * bNeg;
	int maxPos = aPos * bPos;

	return maxPos > maxNeg ? maxPos : maxNeg;
}

int main() {
	int n;
	cin >> n;

	int array[n];
	inputArray(array, n);

	cout << getGreatestProduct(array, n) << endl;
}