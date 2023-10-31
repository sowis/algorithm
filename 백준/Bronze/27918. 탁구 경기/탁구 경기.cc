#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int d = 0, p = 0;

	for (int i = 0; i < N; ++i) {
		char win;
		cin >> win;

		if (win == 'D') {
			++d;
		}
		else {
			++p;
		}

		if (abs(d - p) == 2) {
			break;
		}
	}

	cout << d << ":" << p << "\n";
	return 0;
}