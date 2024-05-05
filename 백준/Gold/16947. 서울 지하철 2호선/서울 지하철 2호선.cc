#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int find_circle(const vector<vector<int>>& edges, vector<bool>& visit, vector<int>& dist, const int cur, const int parent) {
	visit[cur] = true;

	int circle_id = -1;
	for (const int next : edges[cur]) {
		if (next == parent) {
			continue;
		}

		if (visit[next] && dist[next] == -1) {
			dist[cur] = 0;
			return next;
		}

		if (visit[next]) {
			continue;
		}

		circle_id = max(circle_id, find_circle(edges, visit, dist, next, cur));
	}

	if (circle_id == -1) {
		return -1;
	}

	if (cur != circle_id) {
		dist[cur] = 0;
		return circle_id;
	}
	else {
		dist[cur] = 0;
		return -1;
	}
}

int fill_dist(const vector<vector<int>>& edges, vector<int> &dist, const int cur, const int parent) {
	if (dist[cur] >= 0) {
		return dist[cur];
	}

	int d = -1;
	for (const int next : edges[cur]) {
		if (next == parent) {
			continue;
		}

		d = max(d, fill_dist(edges, dist, next, cur));
	}

	if (d == -1) {
		return -1;
	}

	return dist[cur] = d + 1;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<vector<int>> edges(N + 1);
	for (int i = 0; i < N; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	vector<bool> visit(N + 1, false);
	vector<int> dist(N + 1, -1);

	find_circle(edges, visit, dist, 1, -1);

	for (int id = 1; id <= N; ++id) {
		if (dist[id] != -1) {
			continue;
		}

		fill_dist(edges, dist, id, -1);
	}

	for (int id = 1; id <= N; ++id) {
		printf("%d ", dist[id]);
	}

	return 0;
}