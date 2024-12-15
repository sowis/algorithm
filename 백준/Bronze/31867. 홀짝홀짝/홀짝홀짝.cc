#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int even = 0;
	int odd = 0;

	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;

		const int num = c - '0';
		if (num % 2) {
			++odd;
		}
		else {
			++even;
		}
	}

	if (odd == even) {
		cout << -1;
	}
	else if (odd > even) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}