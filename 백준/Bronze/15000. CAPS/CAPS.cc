#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	for (char& c : input) {
		c += 'A' - 'a';
	}

	cout << input;

	return 0;
}