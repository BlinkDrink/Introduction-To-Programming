#include <iostream>
using namespace std;

void inputArray(int array[], int& length);
int getIndex(int& compare, int array[], int& length);

int main() {
	int n;
	cin >> n;

	int array[n];
	inputArray(array, n);

	int compare;
	cin >> compare;

	cout << getIndex(compare, array, n) << endl;
}

void inputArray(int array[], int& length) {
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}
}

int getIndex(int& compare, int array[], int& length) {
	int index = -1;
	for (int i = 0; i < length; i++) {
		if (compare == array[i]) {
			index = i;
			break;
		}
	}
	return index;
}