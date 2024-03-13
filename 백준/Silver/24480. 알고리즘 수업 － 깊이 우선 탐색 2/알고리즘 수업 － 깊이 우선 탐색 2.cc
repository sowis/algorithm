#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const int cur, vector<vector<int>>& edges, vector<bool>& visit, vector<int> &result) {
	static int id = 1;

	visit[cur] = true;
	result[cur] = id;
	++id;

	sort(edges[cur].begin(), edges[cur].end(), greater<int>());
	for (const int next : edges[cur]) {
		if (visit[next]) {
			continue;
		}

		dfs(next, edges, visit, result);
	}
}

int main(void) {
	int N, M, R;
	scanf("%d%d%d", &N, &M, &R);

	vector<vector<int>> edges(N + 1);
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	vector<bool> visit(N + 1, false);
	vector<int> result(N + 1, 0);
	dfs(R, edges, visit, result);

	for (int i = 1; i <= N; ++i) {
		printf("%d\n", result[i]);
	}

	return 0;
}