#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool check(const string& s) {
	unordered_map<char, int> count;

	for (int i = 0; i < s.size(); ++i) {
		++count[s[i]];

		if (count[s[i]] != 3) {
			continue;
		}

		++i;
		if (i == s.size()) {
			return false;
		}

		if (s[i] != s[i - 1]) {
			return false;
		}

		count[s[i]] = 0;
	}

	return true;
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;

		if (check(input)) {
			cout << "OK\n";
		}
		else {
			cout << "FAKE\n";
		}
	}

	return 0;
}