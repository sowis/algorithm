#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool similar(const vector<int>& w1, const vector<int>& w2) {
	vector<int> diff(w1.size(), 0);
	int diff_count = 0;
	vector<int> diff_idx;

	for (int i = 0; i < w1.size(); ++i) {
		if (w1[i] != w2[i]) {
			++diff_count;
			diff[i] = w1[i] - w2[i];
			diff_idx.push_back(i);
		}
	}

	if (diff_count == 0) {
		return true;
	}

	if (diff_count == 1) {
		return abs(diff[diff_idx[0]]) == 1;
	}

	if (diff_count == 2) {
		return (abs(diff[diff_idx[0]]) == 1) && (diff[diff_idx[0]] == -1 * diff[diff_idx[1]]);
	}

	return false;
}

vector<int> str_to_vector(const string& s) {
	vector<int> v('Z' - 'A' + 1, 0);
	for (const char c : s) {
		++v[c - 'A'];
	}

	return v;
}

int main(void) {
	int N;
	cin >> N;

	string target;
	cin >> target;
	const vector<int> target_v = str_to_vector(target);

	int result = 0;

	for (int i = 0; i < N - 1; ++i) {
		string s;
		cin >> s;
		const vector<int> sv = str_to_vector(s);

		if (similar(target_v, sv)) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}