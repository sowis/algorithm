#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

typedef struct _edge {
	int cur;
	int next;
	int capacity;
	int flow;
} Edge;

int N, M;
int begin_y, begin_x;
int end_y, end_x;
vector<vector<char>> board;

constexpr int INF = 987654321;
int MAX;
int ADD;
int SOURCE;
int SINK;
vector<vector<Edge>> edges;

inline int serialize(const int y, const int x) {
	return y * M + x;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	board = vector<vector<char>>(N, vector<char>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];

			if (board[y][x] == 'K') {
				begin_y = y;
				begin_x = x;
			}

			if (board[y][x] == 'H') {
				end_y = y;
				end_x = x;
			}
		}
	}

	MAX = N * M * 2 + 1;
	ADD = N * M;
	SOURCE = serialize(begin_y, begin_x) + ADD;
	SINK = serialize(end_y, end_x);
	edges = vector<vector<Edge>>(MAX);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] == '#' || board[y][x] == 'H') {
				continue;
			}

			const int cur = serialize(y, x);
			edges[cur].push_back({ cur, cur + ADD, 1, 0 });
			edges[cur + ADD].push_back({ cur + ADD, cur, 0, 0 });

			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
					continue;
				}

				if (board[next_y][next_x] == '#') {
					continue;
				}

				const int next = serialize(next_y, next_x);
				edges[cur + ADD].push_back({ cur + ADD, next, INF, 0 });
				edges[next].push_back({ next, cur + ADD, 0, 0 });
			}
		}
	}

	int result = 0;
	while (true) {
		vector<int> prev(MAX, -1);
		vector<bool> visit(MAX, false);
		queue<int> q;

		q.push(SOURCE);
		visit[SOURCE] = true;

		while (q.empty() == false) {
			const int cur = q.front();
			q.pop();

			for (const Edge& e : edges[cur]) {
				if (visit[e.next]) {
					continue;
				}

				if (e.capacity <= e.flow) {
					continue;
				}

				visit[e.next] = true;
				prev[e.next] = cur;
				q.push(e.next);
			}
		}

		if (prev[SINK] == -1) {
			break;
		}

		for (int cur = SINK; prev[cur] != -1; cur = prev[cur]) {
			for (Edge& e : edges[prev[cur]]) {
				if (e.cur == prev[cur] && e.next == cur) {
					++e.flow;
					break;
				}
			}

			for (Edge& e : edges[cur]) {
				if (e.cur == cur && e.next == prev[cur]) {
					--e.flow;
					break;
				}
			}
		}

		++result;

		if (result > N * M) {
			cout << "-1\n";
			return 0;
		}
	}

	cout << result << "\n";

	return 0;
}