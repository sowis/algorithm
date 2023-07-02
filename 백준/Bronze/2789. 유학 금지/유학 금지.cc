#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	string result;
	for (const char c : input) {
		if (c == 'C' || c == 'A' || c == 'M' || c == 'B' || c == 'R' || c == 'I' || c == 'D' || c == 'G' || c == 'E') {
			continue;
		}

		result += c;
	}

	cout << result;

	return 0;
}