#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;

		for (const char c : input) {
			if (c == 'S') {
				cout << input << "\n";
				return 0;
			}
		}
	}

	return 0;
}