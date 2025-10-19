#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct _data {
	int pos;
	int weight;

	bool operator< (const _data& d) const {
		return this->weight < d.weight;
	}
} Data;

int N, M;
int S, E;
vector<vector<pair<int, int>>> edges;

int main(void) {
	cin >> N >> M;
	cin >> S >> E;

	edges = vector<vector<pair<int, int>>>(N + 1);
	for (int i = 0; i < M; ++i) {
		int h1, h2, k;
		cin >> h1 >> h2 >> k;

		edges[h1].push_back({ h2, k });
		edges[h2].push_back({ h1, k });
	}

	priority_queue<Data> q;
	q.push({ S, 987654321 });
	vector<int> max_weights(N + 1, 0);
	max_weights[S] = 987654321;

	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (d.weight > max_weights[d.pos]) {
			continue;
		}

		for (const pair<int, int>&p : edges[d.pos]) {
			const int next_weight = min(d.weight, p.second);
			const int next = p.first;

			if (max_weights[next] >= next_weight) {
				continue;
			}

			max_weights[next] = next_weight;
			q.push({ next, next_weight });
		}
	}

	cout << max_weights[E];

	return 0;
}