#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _serial {
	string str;

	int num_sum(void) const {
		int result = 0;
		for (const char c : str) {
			if ('0' <= c && c <= '9') {
				result += (c - '0');
			}
		}

		return result;
	}

	bool operator< (const struct _serial& s) const {
		if (str.size() != s.str.size()) {
			return str.size() < s.str.size();
		}

		if (this->num_sum() != s.num_sum()) {
			return this->num_sum() < s.num_sum();
		}

		return str < s.str;
	}
} Serial;

int main(void) {
	int N;
	cin >> N;

	vector<Serial> v(N);
	for (Serial& serial : v) {
		cin >> serial.str;
	}

	sort(v.begin(), v.end());

	for (const Serial& s : v) {
		cout << s.str << "\n";
	}

	return 0;
}