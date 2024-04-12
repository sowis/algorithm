#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef struct _data {
	int house;
	int dist;

	bool operator<(const struct _data& d) const {
		return this->dist > d.dist;
	}
} Data;

vector<vector<Data>> edges;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	while (true) {
		cin >> m >> n;

		if (m == 0 && n == 0) {
			break;
		}

		edges = vector<vector<Data>>(m);
		int cost_sum = 0;

		for (int i = 0; i < n; ++i) {
			int x, y, z;
			cin >> x >> y >> z;

			edges[x].push_back({ y, z });
			edges[y].push_back({ x, z });
			cost_sum += z;
		}

		vector<int> distances(m, numeric_limits<int>::max());
		priority_queue<Data> q;
		q.push({ 0, 0 });

		while (q.empty() == false) {
			const Data cur = q.top();
			q.pop();
			
			if (distances[cur.house] <= cur.dist) {
				continue;
			}

			distances[cur.house] = cur.dist;

			for (const Data& next : edges[cur.house]) {
				if (distances[next.house] != numeric_limits<int>::max()) {
					continue;
				}

				q.push(next);
			}
		}

		int tree_sum = 0;
		for (int i = 0; i < m; ++i) {
			tree_sum += distances[i];
		}

		const int result = cost_sum - tree_sum;
		cout << result << "\n";
	}

	return 0;
}