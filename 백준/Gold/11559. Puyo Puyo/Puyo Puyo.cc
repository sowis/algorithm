#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int get_group_size(const vector<vector<char>>& board, vector<vector<bool>> &visit, const int y, const int x) {
	int result = 1;
	visit[y][x] = true;

	for (int d = 0; d < 4; ++d) {
		const int next_y = y + directions[d][0];
		const int next_x = x + directions[d][1];

		if (next_y < 0 || next_y >= 12 || next_x < 0 || next_x >= 6) {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		if (board[y][x] != board[next_y][next_x]) {
			continue;
		}

		result += get_group_size(board, visit, next_y, next_x);
	}

	return result;
}

void erase(vector<vector<char>>& board, const int y, const int x) {
	const char target = board[y][x];
	board[y][x] = '.';

	for (int d = 0; d < 4; ++d) {
		const int next_y = y + directions[d][0];
		const int next_x = x + directions[d][1];

		if (next_y < 0 || next_y >= 12 || next_x < 0 || next_x >= 6) {
			continue;
		}

		if (target != board[next_y][next_x]) {
			continue;
		}

		erase(board, next_y, next_x);
	}
}

bool boom(vector<vector<char>>& board) {
	bool result = false;

	for (int y = 0; y < 12; ++y) {
		for (int x = 0; x < 6; ++x) {
			if (board[y][x] == '.') {
				continue;
			}

			vector<vector<bool>> visit(12, vector<bool>(6, false));
			const int group_size = get_group_size(board, visit, y, x);

			if (group_size < 4) {
				continue;
			}

			erase(board, y, x);
			result = true;
		}
	}

	return result;
}

void go_down(vector<vector<char>>& board) {
	for (int x = 0; x < 6; ++x) {
		while (true) {
			bool change = false;

			for (int y = 11; y >= 1; --y) {
				if (board[y][x] != '.') {
					continue;
				}

				if (board[y - 1][x] == '.') {
					continue;
				}

				board[y][x] = board[y - 1][x];
				board[y - 1][x] = '.';

				change = true;
			}

			if (change == false) {
				break;
			}
		}
	}
}

int main(void) {
	vector<vector<char>> board(12, vector<char>(6));

	for (int y = 0; y < 12; ++y) {
		for (int x = 0; x < 6; ++x) {
			cin >> board[y][x];
		}
	}

	int result = 0;
	while (boom(board)) {
		++result;
		go_down(board);
	}

	cout << result << "\n";

	return 0;
}