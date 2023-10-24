#include <iostream>

using namespace std;

int main(void) {
	int num;
	int result = 0;

	while (cin >> num) {
		result += num;
	}

	cout << result;

	return 0;
}