#include <cstdio>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {-1, 1}, { 0, 1 }, {1, 0}, {1, 1} };

int main(void) {
	vector<vector<int>> board(19, vector<int>(19));

	for (int y = 0; y < 19; ++y) {
		for (int x = 0; x < 19; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	for (int y = 0; y < 19; ++y) {
		for (int x = 0; x < 19; ++x) {
			const int current = board[y][x];

			if (current == 0) {
				continue;
			}

			for (int direction = 0; direction < 4; ++direction) {
				bool finish = true;
				for (int hop = 1; hop < 5; ++hop) {
					const int next_y = y + directions[direction][0] * hop;
					const int next_x = x + directions[direction][1] * hop;

					if (next_y < 0 || next_y >= 19 || next_x < 0 || next_x >= 19) {
						finish = false;
						break;
					}

					if (board[next_y][next_x] != current) {
						finish = false;
						break;
					}
				}

				if (finish == false) {
					continue;
				}

				const int six_y = y + directions[direction][0] * 5;
				const int six_x = x + directions[direction][1] * 5;
				const int before_y = y - directions[direction][0];
				const int before_x = x - directions[direction][1];

				if (six_y >= 0 && six_y < 19 && six_x >= 0 && six_x < 19 && board[six_y][six_x] == current) {
					continue;
				}

				if (before_y >= 0 && before_y < 19 && before_x >= 0 && before_x < 19 && board[before_y][before_x] == current) {
					continue;
				}

				printf("%d\n", current);
				printf("%d %d\n", y + 1, x + 1);
				return 0;
			}
		}
	}

	printf("0\n");

	return 0;
}