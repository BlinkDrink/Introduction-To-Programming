#include <iostream>
using namespace std;

/**
 * Да се напише програма, която въвежда цяло положително число n и печата правоъгълен триъгълник от звездички с размер n.
 */
int main() {
	unsigned int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = n; j >= n - i; j--) {
			cout << '*';
		}
		cout << '\n';
	}
	cout << endl;
}