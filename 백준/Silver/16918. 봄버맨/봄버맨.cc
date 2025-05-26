#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[5][2] = { {0, 0}, { 0, 1 }, {1, 0}, {-1, 0}, {0, -1 } };

int R, C, N;
vector<vector<char>> board;
vector<vector<int>> bomb_set_time;

void set_bombs(const int time) {
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			if (board[y][x] != '.') {
				continue;
			}

			board[y][x] = 'O';
			bomb_set_time[y][x] = time;
		}
	}
}

void boom(const int time) {
	vector<vector<char>> copyboard = board;

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			if (board[y][x] == '.') {
				continue;
			}

			if (time - bomb_set_time[y][x] != 3) {
				continue;
			}

			for (int i = 0; i < 5; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
					continue;
				}

				copyboard[next_y][next_x] = '.';
			}
		}
	}

	board = copyboard;
}

int main(void) {
	cin >> R >> C >> N;

	board = vector<vector<char>>(R, vector<char>(C));
	bomb_set_time = vector<vector<int>>(R, vector<int>(C, 987654321));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];

			if (board[y][x] == 'O') {
				bomb_set_time[y][x] = 0;
			}
		}
	}

	for (int time = 2; time <= N; ++time) {
		set_bombs(time);
		boom(time);
	}
	
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}