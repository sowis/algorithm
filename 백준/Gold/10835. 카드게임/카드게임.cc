#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> left, right;
vector<vector<int>> cache(2001, vector<int>(2001, -1));

int solve(const int left_idx = 0, const int right_idx = 0) {
	int& c = cache[left_idx][right_idx];
	if (c != -1) {
		return c;
	}

	if (left_idx == N || right_idx == N) {
		return c = 0;
	}

	int result = 0;
	result = max(result, solve(left_idx + 1, right_idx + 1)); // 하나씩 버릴 때
	result = max(result, solve(left_idx + 1, right_idx)); // 왼쪽꺼만 버릴 때

	if (left[left_idx] > right[right_idx]) {
		result = max(result, solve(left_idx, right_idx + 1) + right[right_idx]); // 오른쪽꺼만 버릴 때
	}

	return c = result;
}

int main(void) {
	scanf("%d", &N);

	left = vector<int>(N);
	right = vector<int>(N);

	for (int& number : left) {
		scanf("%d", &number);
	}

	for (int& number : right) {
		scanf("%d", &number);
	}

	const int result = solve();

	printf("%d\n", result);

	return 0;
}