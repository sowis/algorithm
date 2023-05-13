#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_set>

using namespace std;

typedef struct _data {
	int node;
	int distance;

	bool operator< (const struct _data& d) const {
		return this->distance > d.distance;
	}
} Data;

int N, M;
vector<pair<int, int>> edges[1001];
unordered_set<int> recovered[1001];

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);

		edges[A].push_back({ B, C });
		edges[B].push_back({ A, C });
	}

	/* dijkstra */
	priority_queue<Data> q;
	vector<int> min_dist(N + 1, numeric_limits<int>::max());
	vector<int> last_node(N + 1, -1);

	min_dist[1] = 0;
	q.push({ 1, 0 });

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.distance > min_dist[d.node]) {
			continue;
		}

		for (const pair<int, int>& edge : edges[d.node]) {
			const int next_dist = d.distance + edge.second;
			const int next_node = edge.first;

			if (min_dist[next_node] <= next_dist) {
				continue;
			}

			min_dist[next_node] = next_dist;
			last_node[next_node] = d.node;
			q.push({ next_node, next_dist });
		}
	}
	/*****************/

	/* edge recover */
	for (int node = 1; node <= N; ++node) {
		int current = node;
		while (current != -1 && last_node[current] != -1) {
			recovered[current].insert(last_node[current]);
			recovered[last_node[current]].insert(current);
			current = last_node[current];
		}
	}
	/***************/

	int result = 0;
	vector<pair<int, int>> recovered_edges;

	for (int node = 1; node <= N; ++node) {
		for (const int next : recovered[node]) {
			if (node > next) {
				continue;
			}

			++result;
			recovered_edges.push_back({ node, next });
		}
	}

	printf("%d\n", result);
	for (const pair<int, int>& p : recovered_edges) {
		printf("%d %d\n", p.first, p.second);
	}

	return 0;
}