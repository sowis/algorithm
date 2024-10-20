#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string N;
	getline(cin, N);

	for (int i = 0; i < stoi(N); ++i) {
		string line;
		getline(cin, line);

		int g = 0, b = 0;
		for (const char c : line) {
			if (c == 'g' || c == 'G') {
				++g;
			}
			else if (c == 'b' || c == 'B') {
				++b;
			}
		}

		if (g > b) {
			cout << line << " is GOOD\n";
		}
		else if (g < b) {
			cout << line << " is A BADDY\n";
		}
		else {
			cout << line << " is NEUTRAL\n";
		}
	}

	return 0;
}