#include <iostream>
using namespace std;

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

bool exists(int compare, int array[], int& length) {
	for (int i = 0; i < length; i++) {
		if (array[i] == compare) return true;
	}
	return false;
}

void printPermutations(int array[], int indices[], int indicesLength, int STATIC_INDEX_ARRAY[], int STATIC_INDEX_LENGTH) {

	if (STATIC_INDEX_LENGTH == indicesLength) {
		cout << "[";
		for (int i = 0; i < STATIC_INDEX_LENGTH; i++) {
			if (i != 0) cout << ", ";
			cout << array[STATIC_INDEX_ARRAY[i]];
		}
		cout << "]" << endl;
		return;
	}

	for (int i = 0; i < indicesLength; i++) {
		if (!exists(indices[i], STATIC_INDEX_ARRAY, STATIC_INDEX_LENGTH)) {
			STATIC_INDEX_ARRAY[STATIC_INDEX_LENGTH] = indices[i];
			printPermutations(array, indices, indicesLength, STATIC_INDEX_ARRAY, STATIC_INDEX_LENGTH + 1);
		}
	}
}

void printPermutations(int array[], int length) {
	int uniqueElements[length];
	int uniqueIndices[length];
	int uniqueLength = 0;

	for (int i = 0; i < length; i++) {
		if (!exists(array[i], uniqueElements, uniqueLength)) {
			uniqueLength++;
			uniqueElements[uniqueLength - 1] = array[i];
			uniqueIndices[uniqueLength - 1] = i;
		}
	}

//	printArray(uniqueElements, uniqueLength);
//	printArray(uniqueIndices, uniqueLength);

	int STATIC_INDEX_ARRAY[length];
	printPermutations(array, uniqueIndices, uniqueLength, STATIC_INDEX_ARRAY, 0);
}

int main() {
	int n;
	cin >> n;

	int array[n];
	inputArray(array, n);

	printPermutations(array, n);
}