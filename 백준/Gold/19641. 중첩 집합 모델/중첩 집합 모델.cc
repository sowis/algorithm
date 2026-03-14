#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> edges;
int root;
vector<pair<int, int>> results;
vector<bool> visit;

int dfs(const int node, const int begin = 1) {
	visit[node] = true;

	int sz = 0;
	for (const int child : edges[node]) {
		if (visit[child]) {
			continue;
		}

		sz += dfs(child, begin + sz + 1);
	}

	results[node].first = begin;
	results[node].second = begin + sz + 1;
	return sz + 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	edges = vector<vector<int>>(N + 1);
	for (int i = 0; i < N; ++i) {
		int	from;
		cin >> from;

		while (true) {
			int to;
			cin >> to;

			if (to == -1) {
				break;
			}

			edges[from].push_back(to);
		}

		sort(edges[from].begin(), edges[from].end());
	}

	cin >> root;

	results = vector<pair<int, int>>(N + 1);
	visit = vector<bool>(N + 1, false);

	dfs(root);

	for (int i = 1; i <= N; ++i) {
		cout << i << " " << results[i].first << " " << results[i].second << "\n";
	}

	return 0;
}