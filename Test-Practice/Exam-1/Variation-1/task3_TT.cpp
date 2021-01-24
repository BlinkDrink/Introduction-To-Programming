#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int &a, int &b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

void inputArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}
}

void printArray(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		if (i != 0) cout << ", ";
		cout << array[i];
	}
	cout << "]" << endl;
}

int main() {
	int n;
	int array[1000];

	double average;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> array[i];
		if (i == 0) average = 1.0 * array[i] / n;
		else average += 1.0 * array[i] / n;
	}

//	cout << "Average = " << average << endl;
	printArray(array, n);

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] >= average) {
			swap(array[i], array[j]);
			j++;
		}
	}

	printArray(array, j);

	return 0;
}