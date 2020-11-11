#include <iostream>
using namespace std;

/**
 * Да се напише програма, която по дадено цяло положително число n отпечатва на конзолата първите n реда от следния шаблон:
 */
int main() {
	unsigned int n;
	cin >> n;

	for (int i = n - 1 ; i > 0; i--) {
		for (int j = 0; j < n-i; j++) {
			cout << j + 1 << ' ';
		}
		cout << endl;
	}
}