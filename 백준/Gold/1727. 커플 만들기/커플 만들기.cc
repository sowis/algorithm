#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr_N;
vector<int> arr_M;
vector<vector<int>> cache;

int solve(const int idx_n = 0, const int idx_m = 0) {
	int& c = cache[idx_n][idx_m];
	if (c != -1) {
		return c;
	}

	if (idx_n == N) {
		return c = 0;
	}

	if (idx_m == M) {
		return c = 1987654321;
	}

	int result = abs(arr_N[idx_n] - arr_M[idx_m]) + solve(idx_n + 1, idx_m + 1);
	result = min(result, solve(idx_n, idx_m + 1));
	return c = result;
}

int main(void) {
	cin >> N >> M;

	arr_N = vector<int>(N);
	for (int& num : arr_N) {
		cin >> num;
	}

	arr_M = vector<int>(M);
	for (int& num : arr_M) {
		cin >> num;
	}

	sort(arr_N.begin(), arr_N.end());
	sort(arr_M.begin(), arr_M.end());

	if (N > M) { // N 이 항상 짧은쪽이 되도록
		swap(N, M);
		swap(arr_N, arr_M);
	}

	cache = vector<vector<int>>(N + 1, vector<int>(M + 1, -1));

	const int result = solve();
	cout << result;

	return 0;
}