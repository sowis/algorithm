#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	char last = -1;
	int len = 1;
	int result = 1;
	for (const char c : input) {
		if (c == last) {
			++len;
		}
		else {
			if (last == 'c') {
				int adding = 26;
				for (int i = 0; i < len - 1; ++i) {
					adding *= 25;
				}

				result *= adding;
			}
			else if (last == 'd') {
				int adding = 10;
				for (int i = 0; i < len - 1; ++i) {
					adding *= 9;
				}

				result *= adding;
			}

			last = c;
			len = 1;
		}
	}

	if (last == 'c') {
		int adding = 26;
		for (int i = 0; i < len - 1; ++i) {
			adding *= 25;
		}

		result *= adding;
	}
	else {
		int adding = 10;
		for (int i = 0; i < len - 1; ++i) {
			adding *= 9;
		}

		result *= adding;
	}

	cout << result;

	return 0;
}