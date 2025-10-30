#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int pos;
	int dist;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

int N, M;
int K;
vector<pair<int, int>> edges[201];
vector<int> friends;
vector<vector<int>> min_distances;

void distance_calculate(const int begin) {
	min_distances[begin][begin] = 0;
	priority_queue<Data> q;
	q.push({ begin, 0 });

	while (q.empty() == false) {
		Data d = q.top();
		q.pop();

		if (min_distances[begin][d.pos] < d.dist) {
			continue;
		}

		for (const pair<int, int>& p : edges[d.pos]) {
			const int next_pos = p.first;
			const int next_dist = d.dist + p.second;

			if (min_distances[begin][next_pos] <= next_dist) {
				continue;
			}

			min_distances[begin][next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b, t;
		cin >> a >> b >> t;

		edges[a].push_back({ b, t });
	}

	cin >> K;
	friends = vector<int>(K);

	for (int& f : friends) {
		cin >> f;
	}

	min_distances = vector<vector<int>>(N + 1, vector<int>(N + 1, 987654321));
	for (int pos = 1; pos <= N; ++pos) {
		distance_calculate(pos);
	}

	vector<int> results;
	int min_max_distance = 987654321;
	for (int pos = 1; pos <= N; ++pos) {
		int max_round_dist = 0;
		for (const int f : friends) {
			max_round_dist = max(max_round_dist, min_distances[pos][f] + min_distances[f][pos]);
		}

		if (max_round_dist < min_max_distance) {
			min_max_distance = max_round_dist;
			results = {};
			results.push_back(pos);
		}
		else if (max_round_dist == min_max_distance) {
			results.push_back(pos);
		}
	}

	for (const int pos : results) {
		cout << pos << " ";
	}

	return 0;
}