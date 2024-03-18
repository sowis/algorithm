#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX = 3003;
constexpr int SOURCE = 3001;
constexpr int SINK = 3002;
int flow[MAX][MAX];
int capacity[MAX][MAX];
vector<int> edges[MAX];

int main(void) {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	for (int id = 1; id <= N; ++id) {
		edges[SOURCE].push_back(id);
		capacity[SOURCE][id] = 1;
	}

	unordered_set<int> available_works;
	for (int id = 1; id <= N; ++id) {
		int work_count;
		scanf("%d", &work_count);

		for (int i = 0; i < work_count; ++i) {
			int work;
			scanf("%d", &work);
			available_works.insert(work);
			work += 1000;

			edges[id].push_back(work);
			edges[work].push_back(id);
			capacity[id][work] = 1;
		}
	}

	for (int work = 1001; work <= M + 1000; ++work) {
		edges[work].push_back(work + 1000);
		edges[work + 1000].push_back(work);
		capacity[work][work + 1000] = 1;

		edges[work + 1000].push_back(SINK);
		edges[SINK].push_back(work + 1000);
		capacity[work + 1000][SINK] = INF;
	}

	int max_flow = 0;
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
				if (flow[cur][next] >= capacity[cur][next]) {
					continue;
				}

				if (visit[next]) {
					continue;
				}

				visit[next] = true;
				prev[next] = cur;
				q.push(next);
			}
		}

		if (prev[SINK] == -1) {
			break;
		}
	
		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			++flow[prev[cur]][cur];
			--flow[cur][prev[cur]];
		}

		++max_flow;
	}

	const int result = min((int)available_works.size(), max_flow + K);
	printf("%d\n", result);

	return 0;
}