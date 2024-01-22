#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int N, M;
unordered_map<int, unordered_set<int>> big_edges;
unordered_map<int, unordered_set<int>> small_edges;

int dfs(const int cur, vector<bool> &visit, unordered_map<int, unordered_set<int>>& edges) {
	visit[cur] = true;
	int result = 1;
	for (const int next : edges[cur]) {
		if (visit[next]) {
			continue;
		}

		result += dfs(next, visit, edges);
	}

	return result;
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		big_edges[a].insert(b);
		small_edges[b].insert(a);
	}

	int result = 0;
	for (int i = 1; i <= N; ++i) {
		vector<bool> visit(N + 1, false);
		const int big_count = dfs(i, visit, big_edges);
		visit = vector<bool>(N + 1, false);
		const int small_count = dfs(i, visit, small_edges);

		if (big_count + small_count == N + 1) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}