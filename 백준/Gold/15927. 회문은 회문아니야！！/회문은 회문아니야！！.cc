#include <iostream>
#include <string>

using namespace std;

bool is_palindrom(const string& s) {
	int left = 0;
	int right = (int)s.size() - 1;

	while (left <= right) {
		if (s[left] != s[right]) {
			return false;
		}

		++left;
		--right;
	}

	return true;
}

bool is_all_same_char(const string& s) {
	const char target = s[0];
	for (const char c : s) {
		if (c != target) {
			return false;
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	if (is_palindrom(str) == false) {
		cout << str.size();
		return 0;
	}

	if (is_all_same_char(str)) {
		cout << -1;
		return 0;
	}

	cout << str.size() - 1;
	
	return 0;
}