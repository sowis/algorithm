#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

enum BOARD_ITEM {
	WALL = '#',
	EMPTY = '.',
	PLAYER = 'J',
	FIRE = 'F'
};

struct hashFunction {
	size_t operator()(const pair<int, int>& x) const {
		return x.first ^ x.second;
	}
};

typedef vector<vector<char>> Board;
typedef unordered_set<pair<int, int>, hashFunction> Shell;

int R, C;
Board board;

Shell get_next_players(const Board& board, const Shell &last_shell) { // 불 번진 보드, 이동 전 플레이어 위치(외곽)
	Shell result;
	for (const pair<int, int>& player : last_shell) {
		for (int i = 0; i < 4; ++i) {
			const int next_y = player.first + directions[i][0];
			const int next_x = player.second + directions[i][1];

			if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
				continue;
			}

			if (board[next_y][next_x] != BOARD_ITEM::EMPTY) {
				continue;
			}

			result.insert({ next_y, next_x });
		}
	}

	return result;
}

Shell get_next_fires(const Board& board, const Shell& last_shell) {
	Shell result;
	for (const pair<int, int>& fire : last_shell) {
		for (int i = 0; i < 4; ++i) {
			const int next_y = fire.first + directions[i][0];
			const int next_x = fire.second + directions[i][1];

			if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
				continue;
			}

			if (board[next_y][next_x] != BOARD_ITEM::EMPTY && board[next_y][next_x] != BOARD_ITEM::PLAYER) {
				continue;
			}

			result.insert({ next_y, next_x });
		}
	}

	return result;
}

bool can_exist(const Board& board) {
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			if (board[y][x] != BOARD_ITEM::PLAYER) {
				continue;
			}

			if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
				return true;
			}
		}
	}

	return false;
}

int main(void) {
	cin >> R >> C;
	board = vector<vector<char>>(R, vector<char>(C));

	Shell player_shell;
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];

			if (board[y][x] == BOARD_ITEM::PLAYER) {
				player_shell.insert({ y, x });
			}
		}
	}

	Shell fire_shell;
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			if (board[y][x] != BOARD_ITEM::FIRE) {
				continue;
			}

			bool nearby_empty_exist = false;

			for (int d = 0; d < 4; ++d) {
				const int next_y = y + directions[d][0];
				const int next_x = x + directions[d][1];

				if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
					continue;
				}

				if (board[next_y][next_x] != BOARD_ITEM::EMPTY && board[next_y][next_x] != BOARD_ITEM::PLAYER) {
					continue;
				}

				nearby_empty_exist = true;
				break;
			}

			if (nearby_empty_exist == false) {
				continue;
			}

			fire_shell.insert({ y, x });
		}
	}

	for (int time = 1; ; ++time) {
		if (player_shell.empty()) {
			cout << "IMPOSSIBLE\n";
			break;
		}

		if (can_exist(board)) {
			cout << time << "\n";
			break;
		}

		const Shell next_fire_shell = get_next_fires(board, fire_shell);
		for (const pair<int, int>& fire : next_fire_shell) {
			board[fire.first][fire.second] = BOARD_ITEM::FIRE;
		}

		const Shell next_player_shell = get_next_players(board, player_shell);
		for (const pair<int, int>& player : next_player_shell) {
			board[player.first][player.second] = BOARD_ITEM::PLAYER;
		}

		fire_shell = next_fire_shell;
		player_shell = next_player_shell;
	}

	return 0;
}