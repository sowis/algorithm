#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX = 103;
constexpr int SOURCE = 101;
constexpr int SINK = 102;

int N, M;
int capacity[MAX][MAX];
int flow[MAX][MAX];
vector<int> edges[MAX];

int get_max_flow(const int source, const int sink) {
	int max_flow = 0;
	while (true) {
		vector<int> prev(MAX, -1);
		queue<int> q;
		q.push(source);

		while (q.empty() == false && prev[sink] == -1) {
			const int cur = q.front();
			q.pop();

			for (const int next : edges[cur]) {
				if (prev[next] != -1) {
					continue;
				}

				if (capacity[cur][next] <= flow[cur][next]) {
					continue;
				}

				prev[next] = cur;
				q.push(next);
			}
		}

		if (prev[sink] == -1) {
			break;
		}

		for (int cur = sink; cur != source; cur = prev[cur]) {
			++flow[prev[cur]][cur];
			--flow[cur][prev[cur]];
		}

		++max_flow;
	}

	return max_flow;
}

void change(const int source, const int sink) {
	vector<int> prev(MAX, -1);
	queue<int> q;
	q.push(source);

	while (q.empty() == false && prev[sink] == -1) {
		const int cur = q.front();
		q.pop();

		for (const int next : edges[cur]) {
			if (cur < source) {
				continue;
			}

			if (cur == source && next < sink) {
				continue;
			}

			if (prev[next] != -1) {
				continue;
			}

			if (capacity[cur][next] <= flow[cur][next]) {
				continue;
			}

			prev[next] = cur;
			q.push(next);
		}
	}

	if (prev[sink] == -1) {
		return;
	}

	flow[source][sink] = 0;
	flow[sink][source] = 0;
	for (int cur = sink; cur != source; cur = prev[cur]) {
		++flow[prev[cur]][cur];
		--flow[cur][prev[cur]];
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	int a_sum = 0;
	for (int i = 1; i <= N; ++i) {
		int cap;
		scanf("%d", &cap);

		edges[SOURCE].push_back(i);
		edges[i].push_back(SOURCE);
		capacity[SOURCE][i] = cap;
		a_sum += cap;
	}

	int b_sum = 0;
	for (int i = 51; i <= M + 50; ++i) {
		int cap;
		scanf("%d", &cap);

		edges[SINK].push_back(i);
		edges[i].push_back(SINK);
		capacity[i][SINK] = cap;
		b_sum += cap;
	}

	if (a_sum != b_sum) {
		printf("-1\n");
		return 0;
	}

	for (int a = 1; a <= N; ++a) {
		for (int b = 51; b <= M + 50; ++b) {
			edges[a].push_back(b);
			edges[b].push_back(a);
			capacity[a][b] = 1;
		}
	}

	const int max_flow = get_max_flow(SOURCE, SINK);
	if (max_flow != a_sum) {
		printf("-1\n");
		return 0;
	}

	for (int a = 1; a <= N; ++a) {
		for (int b = 1; b <= M; ++b) {
			if (flow[a][b + 50] != 1) {
				continue;
			}

			change(a, b + 50);
		}
	}

	for (int a = 1; a <= N; ++a) {
		for (int b = 1; b <= M; ++b) {
			printf("%d", flow[a][b + 50]);
		}
		printf("\n");
	}

	return 0;
}