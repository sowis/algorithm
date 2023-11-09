#include <iostream>
#include <string>

using namespace std;

bool match(const string& s, const int idx, const string &target) {
	if (s.size() - idx < target.size()) {
		return false;
	}

	for (int i = 0; i < target.size(); ++i) {
		if (s[idx + i] != target[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	string s;
	cin >> s;

	int joi = 0;
	int ioi = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'J' && match(s, i, "JOI")) {
			++joi;
		}
		else if (s[i] == 'I' && match(s, i, "IOI")) {
			++ioi;
		}
	}

	cout << joi << "\n";
	cout << ioi << "\n";

	return 0;
}