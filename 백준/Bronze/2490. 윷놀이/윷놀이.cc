#include <iostream>

using namespace std;

int main(void) {
	int input;

	while (cin >> input) {
		int numbers[2] = { 0, 0 };
		++numbers[input];

		for (int i = 0; i < 3; ++i) {
			cin >> input;
			++numbers[input];
		}

		if (numbers[0] == 1) {
			cout << "A\n";
		}
		else if (numbers[0] == 2) {
			cout << "B\n";
		}
		else if (numbers[0] == 3) {
			cout << "C\n";
		}
		else if (numbers[0] == 4) {
			cout << "D\n";
		}
		else {
			cout << "E\n";
		}
	}

	return 0;
}