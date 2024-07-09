#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		string input;
		cin >> input;

		for (char& c : input) {
			if (c == 'Z') {
				c = 'A';
			}
			else {
				++c;
			}
		}

		cout << "String #" << i << "\n";
		cout << input << "\n\n";
	}

	return 0;
}