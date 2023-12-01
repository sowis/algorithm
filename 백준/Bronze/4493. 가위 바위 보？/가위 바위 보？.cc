#include <iostream>

using namespace std;

void test_case(void) {
	int n;
	cin >> n;

	int p1_win = 0, p2_win = 0;
	for (int i = 0; i < n; ++i) {
		char a, b;
		cin >> a >> b;

		if (a == b) {
			continue;
		}

		if (a == 'R') {
			if (b == 'P') {
				++p2_win;
			}
			else {
				++p1_win;
			}
		}
		else if (a == 'P') {
			if (b == 'S') {
				++p2_win;
			}
			else {
				++p1_win;
			}
		}
		else {
			if (b == 'R') {
				++p2_win;
			}
			else {
				++p1_win;
			}
		}
	}

	if (p1_win == p2_win) {
		cout << "TIE\n";
	}
	else if (p1_win > p2_win) {
		cout << "Player 1\n";
	}
	else {
		cout << "Player 2\n";
	}
}

int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		test_case();
	}

	return 0;
}