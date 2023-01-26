#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned int Room;

constexpr int directions[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

int N, M;

bool is_exist_wall(const Room& room, const int direction) {
	return room & (1 << direction);
}

int get_room_size(const vector<vector<Room>>& board, vector<vector<bool>> &visit, const int y, const int x) {
	visit[y][x] = true;

	int result = 1;
	for (int direction = 0; direction < 4; ++direction) {
		if (is_exist_wall(board[y][x], direction)) {
			continue;
		}

		const int next_y = y + directions[direction][0];
		const int next_x = x + directions[direction][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (visit[next_y][next_x]) {
			continue;
		}

		result += get_room_size(board, visit, next_y, next_x);
	}

	return result;
}

void room_fill(const vector<vector<Room>>& board, vector<vector<int>>& visit, const int y, const int x, const int color) {
	visit[y][x] = color;

	for (int direction = 0; direction < 4; ++direction) {
		if (is_exist_wall(board[y][x], direction)) {
			continue;
		}

		const int next_y = y + directions[direction][0];
		const int next_x = x + directions[direction][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (visit[next_y][next_x] != -1) {
			continue;
		}

		room_fill(board, visit, next_y, next_x, color);
	}
}

int main(void) {
	scanf("%d%d", &M, &N);

	vector<vector<Room>> board(N, vector<Room>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	int room_count = 0;
	int max_room_size = 0;
	int color = 0;
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	vector<vector<int>> room_color(N, vector<int>(M, -1));
	vector<vector<int>> room_size(N, vector<int>(M, -1));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (visit[y][x]) {
				continue;
			}
			
			++room_count;
			const int current_room_size = get_room_size(board, visit, y, x);
			max_room_size = max(max_room_size, current_room_size);
			room_fill(board, room_color, y, x, color);
			room_fill(board, room_size, y, x, current_room_size);
			++color;
		}
	}

	int sum_max = max_room_size;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			for (int d = 0; d < 4; ++d) {
				const int next_y = y + directions[d][0];
				const int next_x = x + directions[d][1];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
					continue;
				}

				if (room_color[next_y][next_x] == room_color[y][x]) {
					continue;
				}

				sum_max = max(sum_max, room_size[y][x] + room_size[next_y][next_x]);
			}
		}
	}

	printf("%d\n", room_count);
	printf("%d\n", max_room_size);
	printf("%d\n", sum_max);

	return 0;
}