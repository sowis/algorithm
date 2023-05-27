#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M, R;
unordered_map<int, vector<int>> edges;
vector<bool> visit;
vector<int> result;
int counter = 1;

void dfs(const int current) {
	visit[current] = true;
	result[current] = counter;
	++counter;

	for (const int next : edges[current]) {
		if (visit[next]) {
			continue;
		}

		dfs(next);
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &R);

	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (pair<const int, vector<int>>& edge : edges) {
		vector<int>& links = edge.second;
		sort(links.begin(), links.end());
	}

	visit = vector<bool>(N + 1, false);
	result = vector<int>(N + 1, 0);

	dfs(R);

	for (int i = 1; i <= N; ++i) {
		printf("%d\n", result[i]);
	}

	return 0;
}