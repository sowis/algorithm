#include <cstdio>

using namespace std;

bool board[101][101];

int main(void) {
	for (int i = 0; i < 4; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		for (int y = y1; y < y2; ++y) {
			for (int x = x1; x < x2; ++x) {
				board[y][x] = true;
			}
		}
	}

	int result = 0;
	for (int y = 0; y < 101; ++y) {
		for (int x = 0; x < 101; ++x) {
			if (board[y][x]) {
				++result;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}