#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check(const string& str) {
	vector<bool> count(10, false);
	for (const char c : str) {
		count[c - '0'] = true;
	}

	int result = 0;
	for (const bool c : count) {
		if (c) {
			++result;
		}
	}

	return result;
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string str;
		cin >> str;

		cout << check(str) << "\n";
	}

	return 0;
}