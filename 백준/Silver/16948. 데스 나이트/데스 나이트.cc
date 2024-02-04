#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int directions[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1} };

typedef struct _data {
	int y;
	int x;
	int dist;
} Data;

int main(void) {
	int N;
	scanf("%d", &N);

	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

	if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= N) {
		printf("-1\n");
		return 0;
	}

	if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= N) {
		printf("-1\n");
		return 0;
	}

	vector<vector<int>> board(N, vector<int>(N, 987654321));
	board[r1][c1] = 0;

	queue<Data> q;
	q.push({ r1, c1, 0 });

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		if (board[d.y][d.x] < d.dist) {
			continue;
		}

		for (int i = 0; i < 6; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) {
				continue;
			}

			if (board[next_y][next_x] <= d.dist + 1) {
				continue;
			}

			board[next_y][next_x] = d.dist + 1;
			q.push({ next_y, next_x, d.dist + 1 });
		}
	}

	if (board[r2][c2] == 987654321) {
		printf("-1\n");
	}
	else {
		printf("%d\n", board[r2][c2]);
	}

	return 0;
}