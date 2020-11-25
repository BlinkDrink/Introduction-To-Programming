#include <iostream>
using namespace std;

void inputArray(int array[], int& length) {
	for (int i = 0; i < length; i++) {
		cin >> array[i];
	}
}

double getConvergingProductAverage(int array[], int& length) {
	int sum = 0;
	for (int i = 0; i < (length + 1) / 2; i++) {
		sum += array[i] * array[length - i - 1];
//		cout << array[i] << " " << array[length - i - 1] << endl;
	}
	return 1.0 * sum / ((length + 1) / 2);
}

int main() {
	int n;
	cin >> n;

	int array[n];
	inputArray(array, n);

	cout << getConvergingProductAverage(array, n) << endl;
}