#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string number;
		cin >> number;

		int n = stoi(number);
		reverse(number.begin(), number.end());
		n += stoi(number);
		const string s = to_string(n);
		
		bool diff = false;
		int begin = 0;
		int end = s.size() - 1;
		for (int k = 0; ; ++k) {
			if (begin + k >= end - k) {
				break;
			}

			if (s[begin + k] != s[end - k]) {
				cout << "NO\n";
				diff = true;
				break;
			}
		}

		if (diff == false) {
			cout << "YES\n";
		}
	}

	return 0;
}