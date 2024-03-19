#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int MAX_N = 803;
constexpr int SOURCE = 801;
constexpr int SINK = 802;
constexpr int INF = 987654321;

int N;
int capacity[MAX_N][MAX_N];
int cost[MAX_N][MAX_N];
int flow[MAX_N][MAX_N];
vector<int> edges[MAX_N];

int main(void) {
	int M;
	scanf("%d%d", &N, &M);

	for (int id = 1; id <= N; ++id) {
		edges[SOURCE].push_back(id);
		edges[id].push_back(SOURCE);
		capacity[SOURCE][id] = 1;
	}

	for (int work_id = 1; work_id <= M; ++work_id) {
		edges[SINK].push_back(work_id + 400);
		edges[work_id + 400].push_back(SINK);
		capacity[work_id + 400][SINK] = 1;
	}

	for (int id = 1; id <= N; ++id) {
		int work_count;
		scanf("%d", &work_count);

		for (int k = 0; k < work_count; ++k) {
			int work_id, work_cost;
			scanf("%d%d", &work_id, &work_cost);
			work_id += 400;

			edges[id].push_back(work_id);
			capacity[id][work_id] = 1;
			cost[id][work_id] = -work_cost;

			edges[work_id].push_back(id);
			cost[work_id][id] = +work_cost;
		}
	}

	int min_cost = 0;
	int available_work_count = 0;

	while (true) {
		vector<int> previous(MAX_N, -1);
		vector<int> distance(MAX_N, INF);
		vector<bool> in_queue(MAX_N, false);

		queue<int> q;
		distance[SOURCE] = 0;
		in_queue[SOURCE] = true;
		q.push(SOURCE);

		while (q.empty() == false) {
			const int cur = q.front();
			q.pop();
			in_queue[cur] = false;

			for (const int next : edges[cur]) {
				if (capacity[cur][next] > flow[cur][next] && distance[next] > distance[cur] + cost[cur][next]) {
					distance[next] = distance[cur] + cost[cur][next];
					previous[next] = cur;

					if (in_queue[next] == false) {
						q.push(next);
						in_queue[next] = true;
					}
				}
			}
		}

		if (previous[SINK] == -1) {
			break;
		}

		for (int cur = SINK; cur != SOURCE; cur = previous[cur]) {
			min_cost += cost[previous[cur]][cur] * 1;
			flow[previous[cur]][cur] += 1;
			flow[cur][previous[cur]] -= 1;
		}

		++available_work_count;
	}

	printf("%d\n", available_work_count);
	printf("%d\n", -min_cost);

	return 0;
}