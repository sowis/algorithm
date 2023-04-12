#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	int result = 0;
	for (const char c : input) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}