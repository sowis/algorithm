#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 987654321;
constexpr int EMPTY = -987654321;

int N, P;
int capacity[801][801];
int flow[801][801];
// in: i, out: i+400

int solve(const int source, const int sink) {
	int result = 0;

	while (true) {
		vector<int> parent(801, EMPTY);
		queue<int> q;

		parent[source] = source;
		q.push(source);

		while (q.empty() == false && parent[sink] == EMPTY) {
			int node = q.front();
			q.pop();

			for (int next = 2; next < 801; ++next) {
				if (capacity[node][next] > flow[node][next] && parent[next] == EMPTY) {
					q.push(next);
					parent[next] = node;
				}
			}
		}

		if (parent[sink] == EMPTY) {
			break;
		}

		for (int node = sink; node != source; node = parent[node]) {
			++flow[parent[node]][node];
			--flow[node][parent[node]];
		}

		++result;
	}

	return result;
}

int main(void) {
	scanf("%d%d", &N, &P);

	// in -> out 간선
	for (int node = 1; node <= N; ++node) {
		capacity[node][node + 400] = 1;
	}

	// 노드간 간선
	for (int i = 0; i < P; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		capacity[a + 400][b] = INF; // a out -> b in
		capacity[b + 400][a] = INF; // b out -> a in
	}

	const int result = solve(1 + 400, 2);
	printf("%d\n", result);

	return 0;
}