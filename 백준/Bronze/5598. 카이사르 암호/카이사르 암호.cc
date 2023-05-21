#include <iostream>
#include <string> 

using namespace std;

char change(const char c) {
	if (c < 'D') {
		return 'Z' - ('C' - c);
	}
	else {
		return c - 3;
	}
}

int main(void) {
	string input;
	cin >> input;

	for (char& c : input) {
		c = change(c);
	}

	cout << input << "\n";

	return 0;
}