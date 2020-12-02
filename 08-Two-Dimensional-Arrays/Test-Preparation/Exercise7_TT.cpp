#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void input_2d_array(int** array, size_t row, size_t col) {
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			cin >> array[i][j];
		}
	}
}

void print_2d_array(int** array, size_t row, size_t col) {
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++) {
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
}

int** initArray2D(size_t n, size_t m) {
	int** array = new int*[m];
	for (size_t i = 0; i < m; i++) {
		array[i] = new int[n] {};
	}
	return array;
}

int main() {

	size_t n, m;
	cin >> n >> m;

	int** array = initArray2D(n, m);

	input_2d_array(array, n, m);
	print_2d_array(array, n, m);

	size_t count = 0;
	for (size_t i = 1; i < n - 1; i++) {
		for (size_t j = 1; j < m - 1; j++) {
			bool condition1 = array[i - 1][j] + array[i + 1][j] + array[i][j + 1] + array[i][j - 1] <= array[i][j];
			if (!condition1) continue;

			bool condition2 = array[i - 1][j + 1] + array[i + 1][j] + array[i - 1][j + 1] + array[i - 1][j - 1] <= array[i][j];
			if (!condition2) continue;

			count++;
		}
	}
	cout << count;

	delete[] array;
	return 0;
}