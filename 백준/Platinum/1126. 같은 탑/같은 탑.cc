#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int EMPTY = -2;
constexpr int IMPOSSIBLE = -1;

int N;
vector<int> blocks;
vector<int> reverse_psum;
vector<vector<int>> cache(50, vector<int>(500001, EMPTY));

int solve(const int idx = 0, const int diff = 0) {
	if (idx == N) {
		return (diff == 0) ? 0 : IMPOSSIBLE;
	}

	int& c = cache[idx][diff];
	if (c != EMPTY) {
		return c;
	}

	if (diff > reverse_psum[idx]) {
		return c = IMPOSSIBLE;
	}

	int result = max(solve(idx + 1, abs(diff + blocks[idx])), solve(idx + 1, abs(diff - blocks[idx])));
	if (result != IMPOSSIBLE) {
		result += blocks[idx];
	}

	result = max(result, solve(idx + 1, diff));
	return c = result;
}

int main(void) {
	scanf("%d", &N);

	blocks = vector<int>(N);
	for (int& block : blocks) {
		scanf("%d", &block);
	}

	reverse_psum = vector<int>(N);
	reverse_psum[N - 1] = blocks[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		reverse_psum[i] = reverse_psum[i + 1] + blocks[i];
	}

	const int result = solve();
	if (result == -1 || result == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result / 2);
	}
	

	return 0;
}