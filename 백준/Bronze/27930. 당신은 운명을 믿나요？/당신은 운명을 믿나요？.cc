#include <iostream>
#include <string>

using namespace std;

const string s1 = "YONSEI";
const string s2 = "KOREA";

int main(void) {
	int i1 = 0, i2 = 0;

	string input;
	cin >> input;

	for (const char c : input) {
		if (c == s1[i1]) {
			++i1;
		}

		if (c == s2[i2]) {
			++i2;
		}

		if (i1 == s1.size()) {
			cout << s1 << "\n";
			return 0;
		}

		if (i2 == s2.size()) {
			cout << s2 << "\n";
			return 0;
		}
	}

	return 0;
}