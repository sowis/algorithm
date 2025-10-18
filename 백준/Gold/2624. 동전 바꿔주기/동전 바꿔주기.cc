#include <iostream>
#include <vector>

using namespace std;

int T, K;
vector<int> p;
vector<int> n;
vector<vector<int>> cache;

int solve(const int idx, const int remain) {
	int& c = cache[idx][remain];
	if (c != -1) {
		return c;
	}

	if (remain == 0) {
		return c = 1;
	}

	if (idx == K) {
		return c = 0;
	}

	int result = 0;
	for (int i = 0; i <= n[idx]; ++i) {
		if (remain < p[idx] * i) {
			break;
		}

		result += solve(idx + 1, remain - p[idx] * i);
	}

	return c = result;
}

int main(void) {
	cin >> T >> K;

	p = vector<int>(K);
	n = vector<int>(K);
	cache = vector<vector<int>>(K + 1, vector<int>(T + 1, -1));

	for (int i = 0; i < K; ++i) {
		cin >> p[i] >> n[i];
	}

	const int result = solve(0, T);
	cout << result << "\n";

	return 0;
}