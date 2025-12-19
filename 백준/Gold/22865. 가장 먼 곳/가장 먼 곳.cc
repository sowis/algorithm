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

int N, M;
vector<int> friends_begin;
vector<vector<pair<int, int>>> edges;
vector<vector<int>> min_distances;

void dijkstra(const int friend_id) {
	priority_queue<Data> q;
	q.push({ friends_begin[friend_id], 0 });
	min_distances[friend_id][friends_begin[friend_id]] = 0;

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.dist > min_distances[friend_id][d.pos]) {
			continue;
		}

		for (const pair<int, int>& p : edges[d.pos]) {
			const int next_pos = p.first;
			const int next_dist = d.dist + p.second;

			if (next_dist >= min_distances[friend_id][next_pos]) {
				continue;
			}

			min_distances[friend_id][next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}
}

int pos_value(const int pos) {
	int result = 1987654321;
	for (int friend_id = 0; friend_id < 3; ++friend_id) {
		result = min(result, min_distances[friend_id][pos]);
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	friends_begin = vector<int>(3);
	for (int& f : friends_begin) {
		cin >> f;
	}

	cin >> M;

	edges = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int pos1, pos2, distance;
		cin >> pos1 >> pos2 >> distance;

		edges[pos1].push_back({ pos2, distance });
		edges[pos2].push_back({ pos1, distance });
	}

	min_distances = vector<vector<int>>(3, vector<int>(N + 1, 1987654321));
	for (int friend_id = 0; friend_id < 3; ++friend_id) {
		dijkstra(friend_id);
	}

	int far_pos;
	int far_dist = 0;
	for (int pos = 1; pos <= N; ++pos) {
		const int dist = pos_value(pos);
		if (far_dist < pos_value(pos)) {
			far_pos = pos;
			far_dist = dist;
		}
	}

	cout << far_pos;

	return 0;
}