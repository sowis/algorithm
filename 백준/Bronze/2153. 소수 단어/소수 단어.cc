#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	int number = 0;
	for (const char c : input) {
		if ('a' <= c && c <= 'z') {
			number += c - 'a' + 1;
		}
		else {
			number += c - 'A' + 27;
		}
	}

	for (int div = 2; div < number; ++div) {
		if (number % div == 0) {
			cout << "It is not a prime word.\n";
			return 0;
		}
	}

	cout << "It is a prime word.\n";

	return 0;
}