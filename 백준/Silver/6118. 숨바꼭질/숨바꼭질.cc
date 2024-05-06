#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> edges(N + 1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<int> dist(N + 1, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;

	int max_dist = 0;
	int min_num = 0;
	int count = 0;

	while (q.empty() == false) {
		const int cur = q.front();
		q.pop();

		if (max_dist < dist[cur]) {
			max_dist = dist[cur];
			min_num = cur;
			count = 1;
		}
		else if (max_dist == dist[cur]) {
			min_num = min(min_num, cur);
			++count;
		}

		for (const int next : edges[cur]) {
			if (dist[next] != -1) {
				continue;
			}

			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}
	
	printf("%d %d %d\n", min_num, max_dist, count);

	return 0;
}