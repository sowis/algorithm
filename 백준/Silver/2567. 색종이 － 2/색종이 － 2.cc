#include <cstdio>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool board[101][101];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int left, down;
		scanf("%d%d", &left, &down);

		for (int y = left; y < left + 10; ++y) {
			for (int x = down; x < down + 10; ++x) {
				board[y][x] = true;
			}
		}
	}

	int result = 0;
	for (int y = 1; y <= 100; ++y) {
		for (int x = 1; x <= 100; ++x) {
			if (board[y][x] == false) {
				continue;
			}

			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y > 100 || next_x < 0 || next_x > 100) {
					++result;
					continue;
				}

				if (board[next_y][next_x] == false) {
					++result;
				}
			}
		}
	}

	printf("%d\n", result);

	return 0;
}