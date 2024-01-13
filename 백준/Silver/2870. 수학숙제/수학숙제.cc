#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}

	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}

	return false;
}

int main(void) {
	int N;
	cin >> N;

	vector<string> v;
	for (int i = 0; i < N; ++i) {
		string line;
		cin >> line;

		string num;
		for (const char c : line) {
			if ('0' <= c && c <= '9') {
				if (num[0] == '0') {
					num[0] = c;
				}
				else {
					num += c;
				}
			}
			else {
				if (num.empty()) {
					continue;
				}

				v.push_back(num);
				num = "";
			}
		}

		if (num.empty()) {
			continue;
		}

		v.push_back(num);
		num = "";
	}

	sort(v.begin(), v.end(), cmp);

	for (const string &n : v) {
		cout << n << "\n";
	}

	return 0;
}