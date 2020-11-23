#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void inputArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
}

void printArray(int arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++) {
		if (i != 0) cout << ", ";
		cout << arr[i];
	}
	cout << "]" << endl;
}

int perm(int arr[], unsigned len,
		int res[][1024], unsigned resLen) {

	
}


// Not done
int main() {
	int n = 10;
	int array[n];

	inputArray(array, n);
}
