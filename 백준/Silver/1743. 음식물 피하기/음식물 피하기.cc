#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool board[100][100];
bool visit[100][100];

int N, M;

int get_size(const int y, const int x) {
	int result = 1;
	visit[y][x] = true;

	for (int i = 0; i < 4; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (board[next_y][next_x] == false) {
			continue;
		}

		if (visit[next_y][next_x] == true) {
			continue;
		}

		result += get_size(next_y, next_x);
	}

	return result;
}

int main(void) {
	scanf("%d%d", &N, &M);

	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; ++i) {
		int r, c;
		scanf("%d%d", &r, &c);

		board[r - 1][c - 1] = true;
	}

	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] == false) {
				continue;
			}

			if (visit[y][x]) {
				continue;
			}

			result = max(result, get_size(y, x));
		}
	}

	printf("%d\n", result);

	return 0;
}