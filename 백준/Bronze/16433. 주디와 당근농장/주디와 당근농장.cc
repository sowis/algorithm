#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int grow[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

int main(void) {
	int N, R, C;
	scanf("%d%d%d", &N, &R, &C);

	vector<vector<bool>> board(N, vector<bool>(N, false));
	queue<pair<int, int>> q;

	board[R - 1][C - 1] = true;
	q.push({ R - 1, C - 1 });

	while (q.empty() == false) {
		const pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = p.first + grow[i][0];
			const int next_x = p.second + grow[i][1];

			if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N) {
				continue;
			}

			if (board[next_y][next_x]) {
				continue;
			}

			board[next_y][next_x] = true;
			q.push({ next_y, next_x });
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			printf("%c", board[y][x] ? 'v' : '.');
		}
		printf("\n");
	}

	return 0;
}