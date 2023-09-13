#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N, M;
vector<vector<bool>> visit;
vector<vector<char>> board;
int result = 0;

void dfs(const int y, const int x) {
	visit[y][x] = true;

	if (board[y][x] == 'P') {
		++result;
	}

	for (int i = 0; i < 4; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		if (board[next_y][next_x] == 'X') {
			continue;
		}

		dfs(next_y, next_x);
	}
}

int main(void) {
	cin >> N >> M;

	board = vector<vector<char>>(N, vector<char>(M));
	int begin_y, begin_x;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];

			if (board[y][x] == 'I') {
				begin_y = y;
				begin_x = x;
			}
		}
	}

	visit = vector<vector<bool>>(N, vector<bool>(M, false));
	dfs(begin_y, begin_x);

	if (result == 0) {
		cout << "TT\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}