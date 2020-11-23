#include <iostream>
using namespace std;

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

void wee(int array[], int length) {
	int currVal = array[0];
	int currIdx = 0;
	int currLen = 1;

	int maxVal = currVal;
	int maxIdx = currIdx;
	int maxLen = currLen;

	for (int i = 1; i < length; i++) {
		if (array[i] > currVal) {
			currLen++;
			currVal = array[i];
		}
		else {
			if (currLen > maxLen) {
				maxVal = currVal;
				maxIdx = currIdx;
				maxLen = currLen;
			}

			currVal = array[i];
			currIdx = i;
			currLen = 1;
		}
	}

	cout << "Value: [";
	for (int i = 0; i < maxLen; i++) {
		if (i != 0) cout << ", ";
		cout << array[maxIdx + i];
	}
	cout << "]\n";
	cout << "Index: " << maxIdx << '\n';
	cout << "Length: " << maxLen << endl;
}

int main() {
	int n = 8;
	int array[n];

	inputArray(array, n);
	wee(array, n);
}