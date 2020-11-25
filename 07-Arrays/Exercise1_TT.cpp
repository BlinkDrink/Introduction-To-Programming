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

void printArray(int array[], int& length) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		if (i != 0) cout << ", ";
		cout << array[i];
	}
	cout << "]" << endl;
}

int getSecondGreatest(int array[], int& length) {
	int a = array[0];
	int b = array[1];
	if (a < b) swap(a, b);
	// want: a > b
	for (int i = 2; i < length; i++) {
		if (array[i] > a) {
			b = a;
			a = array[i];
		}
		else if (array[i] > b) {
			b = array[i];
		}
//		cout << "iter " << i << " " << a << " " << b << endl;
	}
	return b;
}

int main() {
	int n;
	cin >> n;

	int array[n];
	inputArray(array, n);

	cout << getSecondGreatest(array, n) << endl;
}
