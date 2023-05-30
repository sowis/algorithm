#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int y = 0, k = 0;
		for (int a = 0; a < 9; ++a) {
			int yp, kp;
			cin >> yp >> kp;

			y += yp;
			k += kp;
		}

		if (y > k) {
			cout << "Yonsei\n";
		}
		else if (y < k) {
			cout << "Korea\n";
		}
		else {
			cout << "Draw\n";
		}
	}

	return 0;
}