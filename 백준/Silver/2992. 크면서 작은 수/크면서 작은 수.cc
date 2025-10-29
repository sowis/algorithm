#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	int last_increase_idx = 0;
	for (int i = 1; i < str.size(); ++i) {
		if (str[i - 1] < str[i]) {
			last_increase_idx = i;
		}
	}

	if (last_increase_idx == 0) {
		cout << 0;
		return 0;
	}

	int right_min_idx = last_increase_idx;
	for (int i = last_increase_idx; i < str.size(); ++i) {
		if (str[last_increase_idx - 1] < str[i] && str[i] < str[last_increase_idx]) {
			right_min_idx = i;
		}
	}

	swap(str[last_increase_idx - 1], str[right_min_idx]);

	string left;
	string right;

	for (int i = 0; i < last_increase_idx; ++i) {
		left += str[i];
	}

	for (int i = last_increase_idx; i < str.size(); ++i) {
		right += str[i];
	}

	sort(right.begin(), right.end());

	const string result = left + right;
	cout << result;

	return 0;
}