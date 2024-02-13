#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[8][2] = { {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1} };
constexpr int SHARK = 17;
constexpr int EMPTY = 0;

typedef struct _data {
	int id;
	int direction;
} Data;

typedef vector<vector<Data>> Board;

pair<int, int> find_fish(const Board &board, const int target_id) {
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			if (board[y][x].id == target_id) {
				return { y, x };
			}
		}
	}

	return { -1, -1 };
}

void fish_move(Board& board) {
	for (int target_fish_id = 1; target_fish_id <= 16; ++target_fish_id) {
		const pair<int, int> pos = find_fish(board, target_fish_id);
		if (pos.first == -1) {
			continue;
		}

		Data &fish = board[pos.first][pos.second];
		for (int i = 0; i < 8; ++i) {
			const int next_y = pos.first + directions[fish.direction][0];
			const int next_x = pos.second + directions[fish.direction][1];

			if (next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4) {
				fish.direction = (fish.direction + 1) % 8;
				continue;
			}

			if (board[next_y][next_x].id == SHARK) {
				fish.direction = (fish.direction + 1) % 8;
				continue;
			}

			swap(board[pos.first][pos.second], board[next_y][next_x]);
			break;
		}
	}
}

int next(Board& board) {
	fish_move(board);

	const pair<int, int> shark_pos = find_fish(board, SHARK);
	const Data& shark = board[shark_pos.first][shark_pos.second];
	const Board board_backup = board;
	int result = 0;

	for (int hop = 1; ; ++hop) {
		const int next_y = shark_pos.first + directions[shark.direction][0] * hop;
		const int next_x = shark_pos.second + directions[shark.direction][1] * hop;

		if (next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4) {
			break;
		}

		Data& prey = board[next_y][next_x];
		if (prey.id == EMPTY) {
			continue;
		}

		int score = prey.id;
		prey.id = EMPTY;
		board[shark_pos.first][shark_pos.second].direction = prey.direction;
		swap(prey, board[shark_pos.first][shark_pos.second]);
		score += next(board);

		result = max(result, score);
		board = board_backup;
	}

	return result;
}

int main(void) {
	Board board(4, vector<Data>(4));

	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 4; ++x) {
			int id, direction;
			scanf("%d%d", &id, &direction);

			board[y][x] = { id, direction % 8 };
		}
	}

	int result = board[0][0].id;
	board[0][0].id = SHARK;
	result += next(board);

	printf("%d\n", result);

	return 0;
}