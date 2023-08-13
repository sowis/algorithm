#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string number;
	cin >> number;

	long long left = 0, right = 0;
	for (int i = 0; i < number.size() / 2; ++i) {
		left += number[i] - '0';
	}

	for (int i = number.size() / 2; i < number.size(); ++i) {
		right += number[i] - '0';
	}

	if (left == right) {
		cout << "LUCKY\n";
	}
	else {
		cout << "READY\n";
	}

	return 0;
}