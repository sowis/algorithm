#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N;

bool avoid(const vector<vector<char>> &board) {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] != 'S') {
				continue;
			}

			for (int direction = 0; direction < 4; ++direction) {
				for (int hop = 1; ; ++hop) {
					const int next_y = y + directions[direction][0] * hop;
					const int next_x = x + directions[direction][1] * hop;

					if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
						break;
					}

					if (board[next_y][next_x] == 'B') {
						break;
					}

					if (board[next_y][next_x] == 'T') {
						return false;
					}
				}
			}
		}
	}

	return true;
}

bool solve(vector<vector<char>>& board, const int last_set_y, const int last_set_x, const int set_count) {
	if (set_count == 3) {
		return avoid(board);
	}

	for (int x = last_set_x + 1; x < N; ++x) {
		if (board[last_set_y][x] != 'X') {
			continue;
		}

		board[last_set_y][x] = 'B';
		if (solve(board, last_set_y, x, set_count + 1)) {
			return true;
		}

		board[last_set_y][x] = 'X';
	}

	for (int y = last_set_y + 1; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] != 'X') {
				continue;
			}

			board[y][x] = 'B';
			if (solve(board, y, x, set_count + 1)) {
				return true;
			}

			board[y][x] = 'X';
		}
	}

	return false;
}

int main(void) {
	cin >> N;

	vector<vector<char>> board(N, vector<char>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] != 'X') {
				continue;
			}

			board[y][x] = 'B';
			if (solve(board, y, x, 1)) {
				cout << "YES\n";
				return 0;
			}

			board[y][x] = 'X';
		}
	}

	cout << "NO\n";

	return 0;
}