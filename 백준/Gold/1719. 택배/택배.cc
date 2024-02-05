#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 987654321;

typedef struct _data {
	int node;
	int dist;
	int first_target;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

int N, M;
vector<vector<pair<int, int>>> edges(201);
vector<vector<int>> result;

void dijkstra(const int begin) {
	vector<int> min_dist(N, INF);
	result[begin] = vector<int>(N, INF);
	result[begin][begin] = INF;
	priority_queue<Data> q;

	q.push({ begin, 0, INF });
	
	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (min_dist[d.node] < d.dist) {
			continue;
		}

		result[begin][d.node] = d.first_target;

		for (const pair<int, int>& p : edges[d.node]) {
			const int next_node = p.first;
			const int next_dist = d.dist + p.second;
			const int next_first_target = (d.first_target == INF) ? next_node : d.first_target;

			if (min_dist[next_node] <= next_dist) {
				continue;
			}

			min_dist[next_node] = next_dist;
			q.push({ next_node, next_dist, next_first_target });
		}
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);

		--a;
		--b;

		edges[a].push_back({ b, t });
		edges[b].push_back({ a, t });
	}
	
	result = vector<vector<int>>(N);

	for (int i = 0; i < N; ++i) {
		dijkstra(i);
	}

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < N; ++k) {
			if (i == k) {
				printf("- ");
			}
			else {
				printf("%d ", result[i][k] + 1);
			}
		}

		printf("\n");
	}

	return 0;
}