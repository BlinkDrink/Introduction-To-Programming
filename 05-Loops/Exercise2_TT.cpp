#include <iostream>
using namespace std;

/*
Да се напише програма, която въвежда цяло положително число n и печата ромбче от звездички с размер n.
Пример:
Вход: 1
Изход: *

Вход: 3
Изход:

  *
 * *
* * *
 * *
  *
*/
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			cout << ' ';
		}
		for (int j = 0; j < 2*i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n - i - 1; j++) {
			cout << ' ';
		}
		for (int j = 0; j < 2*i + 1; j++) {
			cout << '*';
		}
		cout << endl;
	}
}