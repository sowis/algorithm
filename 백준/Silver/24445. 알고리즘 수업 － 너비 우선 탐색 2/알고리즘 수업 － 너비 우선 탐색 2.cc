#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, R;
vector<int> edges[100001];
vector<int> order(100001, 0);
int giver = 1;

void bfs(void) {
	queue<int> q;
	q.push(R);
	order[R] = giver;
	++giver;

	while (q.empty() == false) {
		const int cur = q.front();
		q.pop();

		for (const int next : edges[cur]) {
			if (order[next]) {
				continue;
			}

			order[next] = giver;
			++giver;
			q.push(next);
		}
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &R);

	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 0; i < 100001; ++i) {
		sort(edges[i].begin(), edges[i].end(), greater<int>());
	}

	bfs();

	for (int i = 1; i <= N; ++i) {
		printf("%d\n", order[i]);
	}

	return 0;
}