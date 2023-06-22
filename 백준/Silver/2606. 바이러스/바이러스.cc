#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edges;
vector<bool> visit;

int main(void) {
	int N;
	scanf("%d", &N);

	int edge_count;
	scanf("%d", &edge_count);

	edges = vector<vector<int>>(N + 1);

	for (int i = 0; i < edge_count; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	visit = vector<bool>(N + 1, false);
	queue<int> q;
	q.push(1);
	visit[1] = true;
	int result = 0;

	while (q.empty() == false) {
		const int node = q.front();
		q.pop();

		for (const int next : edges[node]) {
			if (visit[next]) {
				continue;
			}

			visit[next] = true;
			q.push(next);
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}