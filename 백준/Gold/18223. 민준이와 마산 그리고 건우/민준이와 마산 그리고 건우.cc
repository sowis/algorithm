#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct _data {
	int pos;
	int dist;

	bool operator< (const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

int V, E, P;
unordered_map<int, unordered_map<int, int>> edges;

int find_min_distance(const int begin, const int end) {
	vector<int> min_dist(V + 1, 1987654321);
	priority_queue<Data> q;
	q.push({ begin, 0 });
	min_dist[begin] = 0;

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (min_dist[d.pos] > d.dist) {
			continue;
		}

		for (const pair<int, int>& p : edges[d.pos]) {
			const int next_pos = p.first;
			const int next_dist = d.dist + p.second;

			if (min_dist[next_pos] <= next_dist) {
				continue;
			}

			min_dist[next_pos] = next_dist;
			q.push({ next_pos, next_dist });
		}
	}

	return min_dist[end];
}

int main(void) {
	cin >> V >> E >> P;

	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a][b] = c;
		edges[b][a] = c;
	}

	const int direct_dist = find_min_distance(1, V);
	const int begin_to_him_dist = find_min_distance(1, P);
	const int him_to_end_dist = find_min_distance(P, V);

	if (begin_to_him_dist + him_to_end_dist <= direct_dist) {
		cout << "SAVE HIM";
	}
	else {
		cout << "GOOD BYE";
	}

	return 0;
}