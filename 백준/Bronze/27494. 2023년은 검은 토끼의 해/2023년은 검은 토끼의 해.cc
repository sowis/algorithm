#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const string& ans = "2023";

bool ok(const string& s) {
	int ans_idx = 0;
	for (const char c : s) {
		if (c == ans[ans_idx]) {
			++ans_idx;

			if (ans_idx == 4) {
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	int N;
	cin >> N;

	int result = 0;
	for (int i = 1000; i <= N; ++i) {
		if (ok(to_string(i))) {
			++result;
		}
	}

	cout << result;

	return 0;
}