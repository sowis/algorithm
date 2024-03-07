#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX = 203;
constexpr int SOURCE = 201;
constexpr int SINK = 202;

int N, M;
int capacity[MAX][MAX];
int cost[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];

int main(void) {
	scanf("%d%d", &N, &M);

	for (int i = 101; i <= N + 100; ++i) {
		scanf("%d", &capacity[i][SINK]);
		edges[i].push_back(SINK);
		edges[SINK].push_back(i);
	}

	for (int i = 1; i <= M; ++i) {
		scanf("%d", &capacity[SOURCE][i]);
		edges[i].push_back(SOURCE);
		edges[SOURCE].push_back(i);
	}

	for (int bookstore = 1; bookstore <= M; ++bookstore) {
		for (int people = 101; people <= N + 100; ++people) {
			int c;
			scanf("%d", &c);

			cost[bookstore][people] = c;
			cost[people][bookstore] = -c;
			edges[bookstore].push_back(people);
			edges[people].push_back(bookstore);
			capacity[bookstore][people] = INF;
		}
	}

	int cost_sum = 0;
	while (true) {
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

		if (dist[SINK] == INF) {
			break;
		}

		int cur_flow = INF;
		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			cur_flow = min(cur_flow, capacity[prev[cur]][cur] - flow[prev[cur]][cur]);
		}

		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			cost_sum += cost[prev[cur]][cur] * cur_flow;
			flow[prev[cur]][cur] += cur_flow;
			flow[cur][prev[cur]] -= cur_flow;
		}
	}

	printf("%d\n", cost_sum);

	return 0;
}