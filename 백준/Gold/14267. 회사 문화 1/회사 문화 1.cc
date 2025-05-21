#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> edges(N + 1);
	vector<int> cache(N + 1, 0);

	for (int to = 1; to <= N; ++to) {
		int from;
		scanf("%d", &from);

		if (from == -1) {
			continue;
		}

		edges[from].push_back(to);
	}

	for (int i = 0; i < M; ++i) {
		int id, compliment;
		scanf("%d%d", &id, &compliment);

		cache[id] += compliment;
	}

	for (int i = 1; i <= N; ++i) {
		sort(edges[i].begin(), edges[i].end());
	}

	for (int id = 1; id <= N; ++id) {
		for (const int next : edges[id]) {
			cache[next] += cache[id];
		}
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", cache[i]);
	}

	return 0;
}