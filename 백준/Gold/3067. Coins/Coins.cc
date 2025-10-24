#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> coins;
vector<vector<int>> cache;

int solve(const int idx, const int remain) {
	int& c = cache[idx][remain];
	if (c != -1) {
		return c;
	}

	if (remain == 0) {
		return c = 1;
	}

	if (idx == N) {
		return c = 0;
	}

	const int max_use = remain / coins[idx];
	int result = 0;
	for (int use = 0; use <= max_use; ++use) {
		const int next_remain = remain - use * coins[idx];
		if (next_remain < 0) {
			break;
		}

		result += solve(idx + 1, next_remain);
	}

	return c = result;
}

void test_case(void) {
	cin >> N;

	coins = vector<int>(N);
	for (int& coin : coins) {
		cin >> coin;
	}

	cin >> M;

	cache = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

	const int result = solve(0, M);
	cout << result << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}