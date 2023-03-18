#include <cstdio>

using namespace std;

int board[1002][1002];

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		for (int y = a; y < a + c; ++y) {
			for (int x = b; x < b + d; ++x) {
				board[y][x] = i;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		int result = 0;
		for (int y = 0; y < 1002; ++y) {
			for (int x = 0; x < 1002; ++x) {
				if (board[y][x] == i) {
					++result;
				}
			}
		}

		printf("%d\n", result);
	}

	return 0;
}