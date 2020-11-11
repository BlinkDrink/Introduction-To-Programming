#include <iostream>
using namespace std;

/*
Да се напише програма, която по дадено цяло положително число n отпечатва на конзолата първите n реда от следния шаблон:

Вход: 6
Изход:

1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
1 2 3 4 5 6
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