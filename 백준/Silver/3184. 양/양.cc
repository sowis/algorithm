#include <iostream>
#include <vector>

#define wolf first
#define sheep second

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int R, C;

pair<int, int> area(const vector<vector<char>>& board, vector<vector<bool>>& visit, const int y, const int x) {
	visit[y][x] = true;
	pair<int, int> result{ 0, 0 };
	if (board[y][x] == 'v') {
		++result.wolf;
	}
	else if (board[y][x] == 'o') {
		++result.sheep;
	}

	for (int d = 0; d < 4; ++d) {
		const int next_y = y + directions[d][0];
		const int next_x = x + directions[d][1];

		if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		if (board[next_y][next_x] == '#') {
			continue;
		}

		const pair<int, int> p = area(board, visit, next_y, next_x);
		result.wolf += p.wolf;
		result.sheep += p.sheep;
	}

	return result;
}

int main(void) {
	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	vector<vector<bool>> visit(R, vector<bool>(C, false));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];
		}
	}

	int sheep_live = 0;
	int wolf_live = 0;
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			if (board[y][x] == '#') {
				continue;
			}

			if (visit[y][x]) {
				continue;
			}

			const pair<int, int> p = area(board, visit, y, x);
			if (p.sheep > p.wolf) {
				sheep_live += p.sheep;
			}
			else {
				wolf_live += p.wolf;
			}
		}
	}

	cout << sheep_live << " " << wolf_live;

	return 0;
}