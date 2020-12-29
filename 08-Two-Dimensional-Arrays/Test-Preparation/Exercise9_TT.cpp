
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void input_1d_array(double* array, size_t len) {
	for (size_t i = 0; i < len; i++) {
		cin >> array[i];
	}
}

double maxInArray(double* array, size_t len) {
	double max = array[0];
	for (int i = 0; i < len; i++) {
		if (max < array[i]) max = array[i];
	}
	return max;
}

int main() {

	size_t size;
	cin >> size;

	double* array = new double[size];
	input_1d_array(array, size);

	double wallet;
	cin >> wallet;

	while (true) {
		double min = maxInArray(array, size);
		size_t minIndex = -1;

		for (size_t i = 0; i < size; i++) {

			if (array[i] == -1) continue;

			if (minIndex == -1 || array[i] < min) {
//				cout << "assign " << array[i] << endl;
				min = array[i];
				minIndex = i;
			}
		}

		if (minIndex == -1) {
//			cout << "Nothing found" << endl;
			break;
		}

		if (wallet - array[minIndex] >= 0) {
			wallet -= array[minIndex];
			cout << array[minIndex] << endl;

			array[minIndex] = -1;
		}
		else {
			break;
		}
	}
	cout << endl;

	delete[] array;
	return 0;
}