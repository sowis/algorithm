#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s, t;
	while (cin >> s) {
		cin >> t;

		int s_idx = 0;
		for (const char c : t) {
			if (c == s[s_idx]) {
				++s_idx;

				if (s_idx == s.size()) {
					break;
				}
			}
		}

		if (s_idx == s.size()) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	return 0;
}