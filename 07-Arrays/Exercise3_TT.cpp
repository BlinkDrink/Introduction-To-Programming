#include <iostream>
using namespace std;

void inputArray(int array[], int& length) {
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}
}

int getGreatestAdjacentCount(int array[], int& length) {
	int c = 0;
	for (int i = 2; i < length; i++) {
		if (array[i - 2] < array[i - 1] && array[i - 1] > array[i]) c++;
	}
	return c;
}

int main() {
	int n;
	cin >> n;

	int array[n];
	inputArray(array, n);

	cout << getGreatestAdjacentCount(array, n) << endl;
}