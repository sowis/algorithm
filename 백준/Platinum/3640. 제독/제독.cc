#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX = 2001;

const int SOURCE = 1 + 1000;

int v, e;
vector<vector<int>> capacity;
vector<vector<int>> cost;
vector<vector<int>> flow;
vector<vector<int>> edges;

void input(void) {
	cin >> e;

	capacity = vector<vector<int>>(MAX, vector<int>(MAX, 0));
	cost = vector<vector<int>>(MAX, vector<int>(MAX, 0));
	flow = vector<vector<int>>(MAX, vector<int>(MAX, 0));
	edges = vector<vector<int>>(MAX);

	for (int node = 1; node <= v; ++node) {
		edges[node].push_back(node + 1000);
		edges[node + 1000].push_back(node);
		capacity[node][node + 1000] = 1;
	}

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		edges[a + 1000].push_back(b);
		edges[b].push_back(a + 1000);
		capacity[a + 1000][b] = 1;
		cost[a + 1000][b] = c;
		cost[b][a + 1000] = -c;
	}
}

int solve(void) {
	const int SINK = v;
	int cost_sum = 0;
	for (int i = 0; i < 2; ++i) {
		vector<int> dist(MAX, INF);
		vector<int> prev(MAX, -1);
		vector<bool> in_q(MAX, false);

		queue<int> q;
		q.push(SOURCE);
		in_q[SOURCE] = true;
		dist[SOURCE] = 0;

		while (q.empty() == false) {
			const int cur = q.front();
			q.pop();
			in_q[cur] = false;

			for (const int next : edges[cur]) {
				if (dist[next] <= dist[cur] + cost[cur][next]) {
					continue;
				}

				if (capacity[cur][next] <= flow[cur][next]) {
					continue;
				}

				dist[next] = dist[cur] + cost[cur][next];
				prev[next] = cur;

				if (in_q[next] == false) {
					in_q[next] = true;
					q.push(next);
				}
			}
		}

		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			flow[prev[cur]][cur] += 1;
			flow[cur][prev[cur]] -= 1;
			cost_sum += cost[prev[cur]][cur];
		}
	}

	return cost_sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin >> v) {
		input();
		const int result = solve();

		cout << result << "\n";
	}

	return 0;
}