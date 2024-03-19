#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
constexpr int INF = 987654321;

typedef struct _edge {
	int begin;
	int destination;
	int flow;
	int capacity;
} Edge;

inline int serialize(const int y, const int x, const int M) {
	return y * M + x;
}

void test_case(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int number_sum = 0;
	vector<vector<int>> board(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &board[y][x]);
			number_sum += board[y][x];
		}
	}

	const int SOURCE = serialize(N - 1, M - 1, M) + 1;
	const int SINK = SOURCE + 1;
	const int MAX = SINK + 1;
	vector<vector<Edge>> edges(MAX);

	bool red;
	for (int y = 0; y < N; ++y) {
		red = (y % 2) ? true : false;
		for (int x = 0; x < M; ++x) {
			const int cur = serialize(y, x, M);

			if (red) {
				edges[SOURCE].push_back({ SOURCE, cur, 0, board[y][x] });

				for (int i = 0; i < 4; ++i) {
					const int next_y = y + directions[i][0];
					const int next_x = x + directions[i][1];
					if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
						continue;
					}

					const int next = serialize(next_y, next_x, M);

					edges[cur].push_back({ cur, next, 0, INF });
					edges[next].push_back({ next, cur, 0, 0 });
				}
			}
			else {
				edges[cur].push_back({ cur, SINK, 0, board[y][x] });
			}

			red = !red;
		}
	}

	int max_flow = 0;
	while (true) {
		vector<int> prev(MAX, -1);
		queue<int> q;
		q.push(SOURCE);

		while (q.empty() == false && prev[SINK] == -1) {
			const int cur = q.front();
			q.pop();
			
			for (const Edge& edge : edges[cur]) {
				if (prev[edge.destination] != -1) {
					continue;
				}

				if (edge.capacity <= edge.flow) {
					continue;
				}

				prev[edge.destination] = cur;
				q.push(edge.destination);
			}
		}

		if (prev[SINK] == -1) {
			break;
		}

		int cur_flow = INF;
		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			for (Edge& e : edges[prev[cur]]) {
				if (e.destination == cur) {
					cur_flow = min(cur_flow, e.capacity - e.flow);
					break;
				}
			}
		}
	
		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			for (Edge& e : edges[prev[cur]]) {
				if (e.destination == cur) {
					e.flow += cur_flow;
					break;
				}
			}

			for (Edge& e : edges[cur]) {
				if (e.destination == prev[cur]) {
					e.flow -= cur_flow;
					break;
				}
			}
		}

		max_flow += cur_flow;
	}

	printf("%d\n", number_sum - max_flow);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}