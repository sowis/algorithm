#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int result = 0;
vector<unsigned int> flags;

inline unsigned int sub(const unsigned int a, const unsigned int b) {
	return a & (~b);
}

int read_count(const unsigned int readable) {
	int result = 0;
	for (const unsigned int flag : flags) {
		if (sub(flag, readable) == 0) {
			++result;
		}
	}

	return result;
}

void solve(const int index = 0, const unsigned int readable = 0, const int count = 0) {
	if (count == K) {
		result = max(result, read_count(readable));
		return;
	}

	if (index == 26) {
		return;
	}

	if (26 - index + count < K) {
		return;
	}

	solve(index + 1, readable | (1 << index), count + 1);
	solve(index + 1, readable, count);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;

		unsigned int use_flag = 0;
		for (const char c : input) {
			use_flag |= (1 << (c - 'a'));
		}

		flags.push_back(use_flag);
	}

	solve();

	cout << result << "\n";

	return 0;
}