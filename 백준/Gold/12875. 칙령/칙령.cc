#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _data {
	long long pos;
	long long dist;
} Data;

long long N, D;
vector<vector<long long>> edges;

vector<long long> dijkstra(const long long begin) {
	vector<long long> min_dist(N, 1987654321);
	min_dist[begin] = 0;
	queue<Data> q;
	q.push({ begin, 0 });

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (const long long next_pos : edges[d.pos]) {
			const long long next_dist = d.dist + 1;
			if (min_dist[next_pos] <= next_dist) {
				continue;
			}

			min_dist[next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}

	return min_dist;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> D;

	edges = vector<vector<long long>>(N);

	for (long long me = 0; me < N; ++me) {
		for (long long you = 0; you < N; ++you) {
			char op;
			cin >> op;

			if (op == 'Y') {
				edges[me].push_back(you);
			}
		}
	}

	long long result = 0;
	for (long long begin = 0; begin < N; ++begin) {
		const vector<long long> min_dist = dijkstra(begin);
		long long far_dist = 0;
		for (long long target = 0; target < N; ++target) {
			if (far_dist < min_dist[target]) {
				far_dist = min_dist[target];
			}
		}

		if (far_dist == 1987654321) {
			cout << -1;
			return 0;
		}

		result = max(result, far_dist * D);
	}

	cout << result;

	return 0;
}