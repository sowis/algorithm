#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int R, C, K;
int result = 0;

void dfs(const vector<vector<char>>& board, vector<vector<bool>> &visit, const int y, const int x, const int dist) {
	if (dist == K) {
		if (y == 0 && x == C - 1) {
			++result;
		}

		return;
	}

	visit[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
			continue;
		}

		if (board[next_y][next_x] == 'T') {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		dfs(board, visit, next_y, next_x, dist + 1);
	}

	visit[y][x] = false;
}

int main(void) {
	cin >> R >> C >> K;

	vector<vector<char>> board(R, vector<char>(C));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];
		}
	}

	vector<vector<bool>> visit(R, vector<bool>(C, false));
	dfs(board, visit, R - 1, 0, 1);

	cout << result << "\n";

	return 0;
}