#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int main(void) {
	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			if (board[y][x] != 'W') {
				continue;
			}

			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
					continue;
				}

				if (board[next_y][next_x] == 'S') {
					cout << 0 << "\n";
					return 0;
				}

				if (board[next_y][next_x] == '.') {
					board[next_y][next_x] = 'D';
				}
			}
		}
	}

	cout << 1 << "\n";

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}