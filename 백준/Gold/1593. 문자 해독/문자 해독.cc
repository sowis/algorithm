#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_same_vector(const vector<int>& v1, const vector<int>& v2) {
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int G, S;
	cin >> G >> S;

	string w, s;
	cin >> w >> s;

	vector<int> w_chars(27 * 2, 0);
	for (const char c : w) {
		if ('a' <= c && c <= 'z') {
			++w_chars[c - 'a' + 27];
		}
		else {
			++w_chars[c - 'A'];
		}
	}

	int left = 0;
	int right = G;
	vector<int> current_chars(27 * 2, 0);

	for (int i = 0; i < right; ++i) {
		const char c = s[i];
		if ('a' <= c && c <= 'z') {
			++current_chars[c - 'a' + 27];
		}
		else {
			++current_chars[c - 'A'];
		}
	}

	int result = 0;
	if (is_same_vector(w_chars, current_chars)) {
		++result;
	}

	while (right < S) {
		char c = s[left];
		if ('a' <= c && c <= 'z') {
			--current_chars[c - 'a' + 27];
		}
		else {
			--current_chars[c - 'A'];
		}

		++left;

		c = s[right];
		if ('a' <= c && c <= 'z') {
			++current_chars[c - 'a' + 27];
		}
		else {
			++current_chars[c - 'A'];
		}

		++right;

		if (is_same_vector(w_chars, current_chars)) {
			++result;
		}
	}

	cout << result;

	return 0;
}