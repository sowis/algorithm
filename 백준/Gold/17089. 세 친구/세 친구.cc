#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int N, M;
vector<int> edges[4001];
vector<vector<bool>> link(4001, vector<bool>(4001, false));
int result = numeric_limits<int>::max();

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
		link[a][b] = true;
		link[b][a] = true;
	}

	vector<bool> visit(4001, false);
	for (int i = 1; i <= N; ++i) {
		int cur = (int)edges[i].size();
		visit[i] = true;
		for (const int k : edges[i]) {
			if (visit[k]) {
				continue;
			}

			cur += (int)edges[k].size();
			if (result <= cur) {
				cur -= (int)edges[k].size();
				continue;
			}

			visit[k] = true;
			for (const int j : edges[k]) {
				if (link[i][j] == false) {
					continue;
				}

				if (visit[j]) {
					continue;
				}

				cur += (int)edges[j].size();
				result = min(result, cur);
				cur -= (int)edges[j].size();
			}

			visit[k] = false;
			cur -= (int)edges[k].size();
		}

		visit[i] = false;
	}

	if (result == numeric_limits<int>::max()) {
		cout << -1;
	}
	else {
		cout << result - 6;
	}

	return 0;
}