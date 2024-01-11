#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef struct _data {
	int vertex;
	int distance;

	bool operator< (const struct _data& d) const {
		return this->distance > d.distance;
	}
} Data;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	unordered_map<int, unordered_map<int, int>> edges;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		if (edges[a].find(b) == edges[a].end()) {
			edges[a][b] = c;
			edges[b][a] = c;
		}
		else {
			edges[a][b] = min(edges[a][b], c);
			edges[b][a] = min(edges[b][a], c);
		}
	}

	vector<int> min_distance(N + 1, numeric_limits<int>::max());
	priority_queue<Data> q;
	q.push({ 1, 0 });

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (min_distance[d.vertex] <= d.distance) {
			continue;
		}

		min_distance[d.vertex] = d.distance;

		for (const pair<int, int>& p : edges[d.vertex]) {
			const int next_vertex = p.first;
			const int next_distance = d.distance + p.second;

			if (min_distance[next_vertex] <= next_distance) {
				continue;
			}

			q.push({ next_vertex, next_distance });
		}
	}

	printf("%d\n", min_distance[N]);

	return 0;
}