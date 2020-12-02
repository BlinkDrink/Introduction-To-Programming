#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool isSudoku(unsigned** array) {

	// Non-repeating VALID digits in 3x3 squares
	for (int offsetX = 0; offsetX <= 7; offsetX += 3) {
		for (int offsetY = 0; offsetY <= 7; offsetY += 3) {

			bool present_digits[9];
			for (int i = 0; i < 9; i++) {
				present_digits[i] = false;
			}

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					unsigned elem = array[i + offsetX][j + offsetY];

					if (elem < 1 || elem > 9) return false;
					if (present_digits[elem - 1]) return false;

					present_digits[elem - 1] = true;
				}
			}
		}
	}

	for (int i = 0; i < 9; i++) {

		bool present_digits1[9];
		bool present_digits2[9];

		for (int j = 0; j < 9; j++) {
			present_digits1[j] = false;
			present_digits2[j] = false;
		}

		for (int j = 0; j < 9; j++) {
			if (present_digits1[array[i][j] - 1]) return false;
			if (present_digits1[array[j][i] - 1]) return false;
		}
	}
}

int main() {

	return 0;
}