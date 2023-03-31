#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	if (input[0] == '5' && input[1] == '5' && input[2] == '5') {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}