#include <iostream>

using namespace std;


int main(void) {
	int result = 0;

	int input;
	while (cin >> input) {
		if (input > 0) {
			++result;
		}
	}

	cout << result;

	return 0;
}