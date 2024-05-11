#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

constexpr int directions[2][2] = { {0, 1}, {1, 0} };

int N;
int board[3][3];
bool visit[3][3];

int main(void) {
	scanf("%d", &N);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &board[y][x]);
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = true;

	while (q.empty() == false) {
		const pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 2; ++i) {
			const int next_y = p.first + directions[i][0] * board[p.first][p.second];
			const int next_x = p.second + directions[i][1] * board[p.first][p.second];

			if (next_y >= N || next_x >= N) {
				continue;
			}

			if (visit[next_y][next_x]) {
				continue;
			}

			visit[next_y][next_x] = true;
			q.push({ next_y, next_x });
		}
	}

	if (visit[N - 1][N - 1]) {
		printf("HaruHaru\n");
	}
	else {
		printf("Hing\n");
	}

	return 0;
}