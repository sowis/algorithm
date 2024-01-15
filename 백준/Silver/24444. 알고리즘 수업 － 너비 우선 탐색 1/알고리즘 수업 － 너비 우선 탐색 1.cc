#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main(void) {
	int N, M, R;
	scanf("%d%d%d", &N, &M, &R);

	vector<set<int>> edges(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		edges[a].insert(b);
		edges[b].insert(a);
	}

	int count = 1;
	vector<int> visit(N + 1, 0);
	queue<int> q;

	visit[R] = count;
	++count;
	q.push(R);

	while (q.empty() == false) {
		const int cur = q.front();
		q.pop();

		for (int next : edges[cur]) {
			if (visit[next]) {
				continue;
			}

			visit[next] = count;
			++count;
			q.push(next);
		}
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d\n", visit[i]);
	}

	return 0;
}