#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string str;
		cin >> str;

		vector<bool> check(26, false);
		for (const char c : str) {
			check[c - 'A'] = true;
		}

		int result = 0;
		for (int i = 0; i < 26; ++i) {
			if (check[i]) {
				continue;
			}

			result += i + 'A';
		}

		cout << result << "\n";
	}

	return 0;
}