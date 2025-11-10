#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct _data {
	int pos;
	int dist;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

int N, K;
vector<vector<int>> distances;
vector<vector<int>> min_distances;

void dijkstra(const int begin) {
	min_distances[begin][begin] = 0;
	priority_queue<Data> q;
	q.push({ begin, 0 });

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.dist > min_distances[begin][d.pos]) {
			continue;
		}

		for (int next = 0; next < N; ++next) {
			const int next_dist = d.dist + distances[d.pos][next];
			if (min_distances[begin][next] <= next_dist) {
				continue;
			}

			min_distances[begin][next] = next_dist;
			q.push({ next, next_dist });
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;

	distances = vector<vector<int>>(N, vector<int>(N));
	for (int me = 0; me < N; ++me) {
		for (int you = 0; you < N; ++you) {
			cin >> distances[me][you];
		}
	}

	min_distances = vector<vector<int>>(N, vector<int>(N, 1987654321));
	for (int me = 0; me < N; ++me) {
		dijkstra(me);
	}

	vector<int> order(N);
	for (int i = 0; i < N; ++i) {
		order[i] = i;
	}

	int result = 1987654321;
	do {
		if (order[0] != K) {
			continue;
		}

		int cur_pos = K;
		int cur_dist = 0;
		for (int i = 1; i < N; ++i) {
			const int next_pos = order[i];
			cur_dist += min_distances[cur_pos][next_pos];
			cur_pos = next_pos;
		}

		result = min(result, cur_dist);
	} while (next_permutation(order.begin(), order.end()));

	cout << result;

	return 0;
}