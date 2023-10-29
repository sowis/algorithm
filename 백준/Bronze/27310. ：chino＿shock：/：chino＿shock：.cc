#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	int colon = 0;
	int underbar = 0;
	for (const char c : input) {
		if (c == ':') {
			++colon;
		}
		else if (c == '_') {
			++underbar;
		}
	}

	const int result = (int)input.size() + colon + underbar * 5;
	cout << result;

	return 0;
}