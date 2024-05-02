#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(const vector<vector<int>> &edges, const vector<int> &prices, vector<bool> &visit, const int cur) {
	visit[cur] = true;
	int min_price = prices[cur];

	for (const int next : edges[cur]) {
		if (visit[next]) {
			continue;
		}

		min_price = min(min_price, dfs(edges, prices, visit, next));
	}

	return min_price;
}

int main(void) {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	vector<int> prices(N);
	for (int& price : prices) {
		scanf("%d", &price);
	}

	vector<vector<int>> edges(N);
	for (int i = 0; i < M; ++i) {
		int v, w;
		scanf("%d%d", &v, &w);

		--v;
		--w;

		edges[v].push_back(w);
		edges[w].push_back(v);
	}

	int result = 0;
	vector<bool> visit(N, false);
	for (int i = 0; i < N; ++i) {
		if (visit[i]) {
			continue;
		}

		result += dfs(edges, prices, visit, i);
	}

	if (K < result) {
		printf("Oh no\n");
	}
	else {
		printf("%d\n", result);
	}

	return 0;
}