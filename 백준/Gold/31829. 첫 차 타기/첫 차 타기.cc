#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

typedef struct _data {
	int pos;
	long long dist;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

long long N, K, X, Y;
vector<vector<pair<int, long long>>> edge_walk;
vector<vector<pair<int, long long>>> edge_bus;

int main(void) {
	cin >> N >> K >> X >> Y;

	edge_walk = vector<vector<pair<int, long long>>>(N + 1);
	edge_bus = vector<vector<pair<int, long long>>>(N + 1);
	for (int i = 0; i < X; ++i) {
		int s, e;
		long long d;
		cin >> s >> e >> d;

		edge_walk[s].push_back({ e, d });
		edge_walk[e].push_back({ s, d });
	}

	for (int i = 0; i < Y; ++i) {
		int s, e;
		long long d;
		cin >> s >> e >> d;

		edge_bus[s].push_back({ e, d });
		edge_bus[e].push_back({ s, d });
	}

	vector<long long> min_distance(N + 1, numeric_limits<long long>::max());
	priority_queue<Data> q;
	q.push({ 1, 0 });
	min_distance[1] = 0;

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.dist > min_distance[d.pos]) {
			continue;
		}

		for (const pair<int, long long >& p : edge_walk[d.pos]) {
			const int next_pos = p.first;
			const long long next_dist = d.dist + p.second;

			if (next_dist >= min_distance[next_pos]) {
				continue;
			}

			min_distance[next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}

		const long long bus_wait = max(K, d.dist);
		for (const pair<int, long long>& p : edge_bus[d.pos]) {
			const int next_pos = p.first;
			const long long next_dist = bus_wait + p.second;

			if (next_dist >= min_distance[next_pos]) {
				continue;
			}

			min_distance[next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}

	cout << min_distance[N];

	return 0;
}