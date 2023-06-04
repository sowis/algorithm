#include <iostream>
#include <string>

using namespace std;

bool match(const string& re, const string& target, const int re_index = 0, const int target_index = 0) {
	if (re.size() == re_index && target.size() == target_index) {
		return true;
	}

	if (re.size() == re_index || target.size() == target_index) {
		return false;
	}

	if (re[re_index] == '*') {
		for (int i = target_index; i < target.size(); ++i) {
			if (match(re, target, re_index + 1, i)) {
				return true;
			}
		}

		return false;
	}

	if (re[re_index] == target[target_index]) {
		return match(re, target, re_index + 1, target_index + 1);
	}

	return false;
}

int main(void) {
	int N;
	cin >> N;

	string re;
	cin >> re;

	for (int i = 0; i < N; ++i) {
		string target;
		cin >> target;

		if (match(re, target)) {
			cout << "DA\n";
		}
		else {
			cout << "NE\n";
		}
	}

	return 0;
}