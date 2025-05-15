#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int dfs(const int current, const vector<vector<int>> &edge) {
	queue<int> q;
	vector<bool> visit(edge.size(), false);
	q.push(current);
	visit[current] = true;
	int result = 1;

	while (q.empty() == false) {
		const int node = q.front();
		q.pop();

		for (const int next : edge[node]) {
			if (visit[next]) {
				continue;
			}

			visit[next] = true;
			q.push(next);
			++result;
		}
	}

	return result;
}

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> edge(N + 1);
	vector<vector<int>> reverse_edge(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		edge[a].push_back(b);
		reverse_edge[b].push_back(a);
	}

	int result = 0;
	for (int i = 1; i <= N; ++i) {
		if (dfs(i, edge) - 1 > (N / 2)) {
			++result;
			continue;
		}

		if (dfs(i, reverse_edge) - 1 > (N / 2)) {
			++result;
			continue;
		}
	}

	printf("%d", result);

	return 0;
}