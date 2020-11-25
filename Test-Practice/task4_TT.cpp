#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	int array[10][10];
	int n, nSquared;

	cin >> n;
	nSquared = n * n;

	int totalSum = 0;
	int expectedTotalSum = nSquared * (nSquared + 1) / 2; // Sum of elements from 1 to nSquared
	int expectedLocalSum = expectedTotalSum / n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
			totalSum += array[i][j];
		}
	}

	if (totalSum != expectedTotalSum) {
		cout << "No" << endl;
		return 0;
	}

	int sumMainDiag = 0;
	int sumSecondaryDiag = 0;
	for (int i = 0; i < n; i++) {
		int sumRows = 0;
		int sumColumns = 0;

		sumMainDiag += array[i][i];
		sumSecondaryDiag += array[i][n - 1 - i];

		for (int j = 0; j < n; j++) {
			sumRows += array[i][j];
			sumColumns += array[j][i];
		}

		if (sumRows != expectedLocalSum || sumColumns != expectedLocalSum) {
			cout << "No" << endl;
			return 0;
		}
	}
	if (sumMainDiag != expectedLocalSum || sumSecondaryDiag != expectedLocalSum) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	return 0;
}