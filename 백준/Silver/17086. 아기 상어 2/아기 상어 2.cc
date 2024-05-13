#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int directions[8][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

typedef struct _data {
	int y;
	int x;
	int dist;
} Data;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> board(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	vector<vector<int>> safe_distance(N, vector<int>(M, 987654321));
	vector<vector<bool>> visit;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] == 0) {
				continue;
			}

			visit = vector<vector<bool>>(N, vector<bool>(M, false));
			queue<Data> q;
			q.push({ y, x, 0 });
			visit[y][x] = true;

			while (q.empty() == false) {
				const Data d = q.front();
				q.pop();

				safe_distance[d.y][d.x] = min(safe_distance[d.y][d.x], d.dist);

				for (int i = 0; i < 8; ++i) {
					const int next_y = d.y + directions[i][0];
					const int next_x = d.x + directions[i][1];

					if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
						continue;
					}

					if (visit[next_y][next_x]) {
						continue;
					}

					visit[next_y][next_x] = true;
					q.push({ next_y, next_x, d.dist + 1 });
				}
			}
		}
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			result = max(result, safe_distance[y][x]);
		}
	}

	printf("%d\n", result);

	return 0;
}