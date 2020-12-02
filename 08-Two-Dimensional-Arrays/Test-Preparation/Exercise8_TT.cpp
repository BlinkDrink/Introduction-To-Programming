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
	int** array = new int*[n];
	for (size_t i = 0; i < n; i++) {
		array[i] = new int[m] {};
	}
	return array;
}

int main() {

	size_t aY, aX;
	cin >> aY >> aX;
	int** a = initArray2D(aY, aX);
	input_2d_array(a, aY, aX);
	print_2d_array(a, aY, aX);

	size_t bY, bX;
	cin >> bY >> bX;
	int** b = initArray2D(bY, bX);
	input_2d_array(b, bY, bX);
	print_2d_array(b, bY, bX);

	if (aX != bY) return 1;

	// 4x2 * 2x3 = 4x3
	size_t cY = aY;
	size_t cX = bX;
	int** c = initArray2D(cY, cX);

	size_t inner = aX; // = bY
	for (size_t i = 0; i < cY; i++) {
		for (size_t j = 0; j < cX; j++) {
			c[i][j] = 0;

			for (size_t k = 0; k < inner; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	print_2d_array(c, cY, cX);

	delete[] a;
	delete[] b;
	return 0;
}