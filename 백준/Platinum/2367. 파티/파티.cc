#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX = 303;
constexpr int SOURCE = 301;
constexpr int SINK = 302;

int N, K, D;
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];

int main(void) {
	scanf("%d%d%d", &N, &K, &D);

	for (int people = 1; people <= N; ++people) {
		capacity[SOURCE][people] = K;
		edges[SOURCE].push_back(people);
		edges[people].push_back(SOURCE);
	}

	for (int food = 201; food <= D + 200; ++food) {
		scanf("%d", &capacity[food][SINK]);
		edges[food].push_back(SINK);
		edges[SINK].push_back(food);
	}

	for (int people = 1; people <= N; ++people) {
		int z_count;
		scanf("%d", &z_count);

		for (int i = 0; i < z_count; ++i) {
			int food;
			scanf("%d", &food);
			food += 200;

			capacity[people][food] = 1;
			edges[people].push_back(food);
			edges[food].push_back(people);
		}
	}

	int result = 0;

	while (true) {
		vector<int> prev(MAX, -1);
		vector<bool> visit(MAX, false);

		queue<int> q;
		q.push(SOURCE);
		visit[SOURCE] = true;

		while (q.empty() == false) {
			const int cur = q.front();
			q.pop();

			for (const int next : edges[cur]) {
				if (capacity[cur][next] <= flow[cur][next]) {
					continue;
				}

				if (visit[next]) {
					continue;
				}

				prev[next] = cur;
				visit[next] = true;
				q.push(next);
			}
		}

		if (prev[SINK] == -1) {
			break;
		}

		int cur_flow = 987654321;
		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			cur_flow = min(cur_flow, capacity[prev[cur]][cur] - flow[prev[cur]][cur]);
		}

		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			flow[prev[cur]][cur] += cur_flow;
			flow[cur][prev[cur]] -= cur_flow;
		}

		result += cur_flow;
	}

	printf("%d\n", result);

	return 0;
}