#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<vector<int>> board(100, vector<int>(100, 0));
	for (int i = 0; i < N; ++i) {
		int y1, x1, y2, x2;
		scanf("%d%d%d%d", &y1, &x1, &y2, &x2);

		for (int y = y1 - 1; y < y2; ++y) {
			for (int x = x1 - 1; x < x2; ++x) {
				++board[y][x];
			}
		}
	}

	int result = 0;
	for (int y = 0; y < 100; ++y) {
		for (int x = 0; x < 100; ++x) {
			if (board[y][x] > M) {
				++result;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}