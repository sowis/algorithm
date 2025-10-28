#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int find_min(const string& str, const vector<bool>& visit, const int begin, const int end) {
	char min_c = numeric_limits<char>::max();
	int idx = -1;

	for (int i = begin; i < end; ++i) {
		if (visit[i]) {
			continue;
		}

		if (min_c <= str[i]) {
			continue;
		}

		min_c = str[i];
		idx = i;
	}

	return idx;
}

void str_print(const string& str, const vector<bool>& visit) {
	for (int i = 0; i < str.size(); ++i) {
		if (visit[i]) {
			cout << str[i];
		}
	}

	cout << "\n";
}

bool solve(const string& str, vector<bool>& visit, const int begin, const int end) {
	const int new_idx = find_min(str, visit, begin, end);
	if (new_idx == -1) {
		return false;
	}

	visit[new_idx] = true;
	str_print(str, visit);

	if (solve(str, visit, new_idx, end)) {
		return true;
	}

	return solve(str, visit, begin, end);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;

	vector<bool> visit(str.size(), false);

	solve(str, visit, 0, (int)str.size());

	return 0;
}