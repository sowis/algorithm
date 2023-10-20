#include <iostream>
#include <string>

using namespace std;

const string str = "MOBIS";

bool exist(const string& s, const char target) {
	for (const char c : s) {
		if (target == c) {
			return true;
		}
	}

	return false;
}

int main(void) {
	string input;
	cin >> input;

	for (const char target : str) {
		if (exist(input, target) == false) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}