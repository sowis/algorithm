#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	int result = 1;
	char cur = 'a';

	for (const char c : input) {
		if (cur > c) {
			++result;
		}

		cur = c + 1;
	}

	cout << result << "\n";

	return 0;
}