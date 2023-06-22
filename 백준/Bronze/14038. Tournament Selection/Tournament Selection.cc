#include <iostream>

using namespace std;

int main(void) {
	int win_count = 0;
	
	for (int i = 0; i < 6; ++i) {
		char c;
		cin >> c;

		if (c == 'W') {
			++win_count;
		}
	}

	if (win_count >= 5) {
		cout << "1\n";
	}
	else if (win_count >= 3) {
		cout << "2\n";
	}
	else if (win_count >= 1) {
		cout << "3\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}