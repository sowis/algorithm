#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int EMPTY = 1987654321;

int main(void) {
	int C, N;
	scanf("%d%d", &C, &N);

	vector<pair<int, int>> datas(N);
	for (pair<int, int>& p : datas) {
		scanf("%d%d", &p.first, &p.second);
	}

	vector<vector<int>> cache(C + 1, vector<int>(N + 1, EMPTY));
	cache[C][0] = 0;

	for (int n = 0; n < N; ++n) {
		for (int c = C; c >= 0; --c) {
			int& ch = cache[c][n];
			if (ch == EMPTY) {
				continue;
			}

			int i = 0;
			for (; datas[n].second * i < c; ++i) {
				cache[c - datas[n].second * i][n + 1] = min(cache[c - datas[n].second * i][n + 1], ch + datas[n].first * i);
			}

			cache[0][n + 1] = min(cache[0][n + 1], ch + datas[n].first * i);
		}
	}

	int result = 1987654321;
	for (int n = 0; n <= N; ++n) {
		result = min(result, cache[0][n]);
	}

	printf("%d\n", result);

	return 0;
}