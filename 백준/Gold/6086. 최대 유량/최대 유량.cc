#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
constexpr int MAX = 200;
constexpr int SOURCE = 'A';
constexpr int SINK = 'Z';

int capacity[MAX][MAX];
int flow[MAX][MAX];
unordered_set<int> edge[MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		char begin, end;
		int cap;

		cin >> begin >> end >> cap;

		capacity[begin][end] += cap;
		capacity[end][begin] += cap;
		edge[begin].insert(end);
		edge[end].insert(begin);
	}

	int max_flow = 0;
	while (true) {
		vector<int> prev(MAX, -1);
		queue<int> q;

		q.push(SOURCE);

		while (q.empty() == false && prev[SINK] == -1) {
			const int cur = q.front();
			q.pop();

			for (const int next : edge[cur]) {
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

		if (prev[SINK] == -1) {
			break;
		}

		int cur_flow = INF;
		for (int cur = SINK; cur != SOURCE; cur = prev[cur]) {
			cur_flow = min(cur_flow, capacity[prev[cur]][cur] - flow[prev[cur]][cur]);
		}

		for (int cur = SINK; cur != SOURCE; cur = prev[cur]) {
			flow[prev[cur]][cur] += cur_flow;
			flow[cur][prev[cur]] -= cur_flow;
		}

		max_flow += cur_flow;
	}

	cout << max_flow;

	return 0;
}