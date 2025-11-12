#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> counts;
unordered_map<string, int> begin_idx;

bool is_prefix(const string& prefix, const string& str) {
	if (str.size() < prefix.size()) {
		return false;
	}

	for (int i = 0; i < prefix.size(); ++i) {
		if (str[i] != prefix[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int start_idx = 1987654321;
	string max_prefix;
	vector<string> strs;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;
		strs.push_back(str);

		string cur;
		for (const char c : str) {
			cur += c;

			if (counts[cur] > 0) {
				if (max_prefix.size() < cur.size()) {
					start_idx = begin_idx[cur];
					max_prefix = cur;
				}
				else if (max_prefix.size() == cur.size() && begin_idx[cur] < start_idx) {
					start_idx = begin_idx[cur];
					max_prefix = cur;
				}
			}

			if (counts[cur] == 0) {
				begin_idx[cur] = i;
			}

			++counts[cur];
		}
	}

	string S, T;
	bool find_s = false;

	for (const string& str : strs) {
		if (is_prefix(max_prefix, str) == false) {
			continue;
		}

		if (find_s) {
			T = str;
			break;
		}

		S = str;
		find_s = true;
	}

	cout << S << "\n";
	cout << T << "\n";

	return 0;
}