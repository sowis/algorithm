#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

typedef struct _data {
	int y;
	int x;
	int dist;
} Data;

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<vector<int>> board(n, vector<int>(m));
	Data begin;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			scanf("%d", &board[y][x]);

			if (board[y][x] == 2) {
				begin = { y, x, 0 };
			}
		}
	}

	vector<vector<int>> distances(n, vector<int>(m, -1));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<Data> q;
	q.push(begin);
	visit[begin.y][begin.x] = true;
	distances[begin.y][begin.x] = 0;

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m) {
				continue;
			}

			if (visit[next_y][next_x] == true) {
				continue;
			}

			visit[next_y][next_x] = true;
			if (board[next_y][next_x] == 0) {
				continue;
			}

			distances[next_y][next_x] = d.dist + 1;
			q.push({ next_y, next_x, d.dist + 1 });
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (board[y][x] == 0) {
				distances[y][x] = 0;
			}
		}
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			printf("%d ", distances[y][x]);
		}
		printf("\n");
	}

	return 0;
}