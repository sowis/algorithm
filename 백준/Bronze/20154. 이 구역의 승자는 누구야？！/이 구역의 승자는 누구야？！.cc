#include <string>
#include <iostream>

using namespace std;

const int lines[27] = { 3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1 };

int main(void) {
	string input;
	cin >> input;

	int result = 0;
	for (const char c : input) {
		result += lines[c - 'A'];
	}

	if (result % 2) {
		cout << "I'm a winner!";
	}
	else {
		cout << "You're the winner?";
	}

	return 0;
}