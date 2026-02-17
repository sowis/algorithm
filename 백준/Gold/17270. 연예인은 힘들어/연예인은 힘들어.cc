#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct _pos {
	int pos;
	int dist;

	bool operator< (const struct _pos& p) const {
		return this->dist > p.dist;
	}
} Pos;

int V, M;
int J, S;
vector<pair<int, int>> edges[1001];

vector<int> dijkstra(const int begin) {
	vector<int> result(V + 1, 1987654321);
	result[begin] = 0;

	priority_queue<Pos> q;
	q.push({ begin, 0 });

	while (q.empty() == false) {
		const Pos pos = q.top();
		q.pop();

		if (pos.dist > result[pos.pos]) {
			continue;
		}

		for (const pair<int, int>& p : edges[pos.pos]) {
			const int next = p.first;
			const int next_dist = pos.dist + p.second;

			if (result[next] <= next_dist) {
				continue;
			}

			result[next] = next_dist;
			q.push({ next, next_dist });
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V >> M;

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cin >> J >> S;

	vector<int> s_dist = dijkstra(S);
	vector<int> j_dist = dijkstra(J);

	int result_pos = 0;
	j_dist[0] = 987654321;
	int dist_sum_min = 1987654321;
	for (int pos = 1; pos <= V; ++pos) {
		if (pos == S || pos == J) {
			continue;
		}

		dist_sum_min = min(dist_sum_min, s_dist[pos] + j_dist[pos]);
	}

	for (int pos = 1; pos <= V; ++pos) {
		if (pos == S || pos == J) {
			continue;
		}

		if (s_dist[pos] + j_dist[pos] != dist_sum_min) {
			continue;
		}

		if (j_dist[pos] > s_dist[pos]) {
			continue;
		}

		if (j_dist[pos] < j_dist[result_pos]) {
			result_pos = pos;
		}
	}

	if (result_pos == 0) {
		result_pos = -1;
	}

	cout << result_pos;

	return 0;
}