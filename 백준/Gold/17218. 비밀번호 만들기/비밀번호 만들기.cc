#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const string EMPTY = "-1";

string a, b;
vector<vector<string>> cache;

string solve(const int a_idx, const int b_idx) {
	string& c = cache[a_idx][b_idx];
	if (c != EMPTY) {
		return c;
	}

	if (a_idx >= a.size() || b_idx >= b.size()) {
		return c = "";
	}

	string result = "";
	for (int i = a_idx; i < a.size(); ++i) {
		for (int k = b_idx; k < b.size(); ++k) {
			if (a[i] != b[k]) {
				continue;
			}

			const string next_str = string{ a[i] } + solve(i + 1, k + 1);
			if (next_str.size() > result.size()) {
				result = next_str;
			}
		}
	}

	return c = result;
}

int main(void) {
	cin >> a >> b;

	cache = vector<vector<string>>(a.size() + 1, vector<string>(b.size() + 1, EMPTY));
	cout << solve(0, 0);

	return 0;
}