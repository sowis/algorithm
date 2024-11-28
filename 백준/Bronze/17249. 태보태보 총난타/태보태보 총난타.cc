#include <iostream>

using namespace std;

int main(void) {
	bool is_left = true;
	int left = 0;
	int right = 0;

	char c;
	while (cin >> c) {
		if (c == '0') {
			is_left = false;
		}

		if (c == '@') {
			if (is_left) {
				++left;
			}
			else {
				++right;
			}
		}
	}

	cout << left << " " << right;

	return 0;
}