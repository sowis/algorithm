#include <cstdio>
#include <vector>

using namespace std;

constexpr int directions[8][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1} };

void dfs(const vector<vector<int>>& board, vector<vector<bool>>& visit, const int y, const int x, const int M, const int N) {
	visit[y][x] = true;

	for (int i = 0; i < 8; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || M <= next_y || next_x < 0 || N <= next_x) {
			continue;
		}

		if (board[next_y][next_x] == 0) {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		dfs(board, visit, next_y, next_x, M, N);
	}
}

int main(void) {
	int M, N;
	scanf("%d%d", &M, &N);

	vector<vector<int>> board(M, vector<int>(N));
	vector<vector<bool>> visit(M, vector<bool>(N, false));
	for (int y = 0; y < M; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	int result = 0;
	for (int y = 0; y < M; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] == 0) {
				continue;
			}

			if (visit[y][x]) {
				continue;
			}

			dfs(board, visit, y, x, M, N);
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}