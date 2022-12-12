#include <cstdio>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> cache(33, vector<int>(33, -1));

int nCr(const int n, const int r) {
	int& c = cache[n][r];
	if (c != -1) {
		return c;
	}

	if (r == 0 || n == r) {
		return c = 1;
	}

	return c = nCr(n - 1, r) + nCr(n - 1, r - 1);
}

int main(void) {
	scanf("%d%d%d", &N, &M, &K);

	if (K == 0) {
		const int result = nCr(N + M - 2, N - 1);
		printf("%d\n", result);
	}
	else {
		--K;
		const int half_y = K / M;
		const int half_x = K % M;

		const int half = nCr(half_y + half_x, half_y);
		const int another_half = nCr(N - half_y - 1 + M - half_x - 1, N - half_y - 1);

		printf("%d\n", half * another_half);
	}

	return 0;
}