#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Board;

typedef struct _data {
	int y;
	int x;
	int dist;
} Data;

enum BOARD {
	EMPTY = 0,
	WALL = 1,
	SWORD = 2
};

enum DISTANCE {
	INF = 987654321
};

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int N, M, T;
int sword_y, sword_x;

int main(void) {
	scanf("%d%d%d", &N, &M, &T);

	Board board(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &board[y][x]);

			if (board[y][x] == BOARD::SWORD) {
				sword_y = y;
				sword_x = x;
			}
		}
	}

	queue<Data> q;
	Board distances(N, vector<int>(M, DISTANCE::INF));
	q.push({ 0, 0, 0 });
	distances[0][0] = 0;

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();
		
		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];
			const int next_dist = d.dist + 1;
			
			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (board[next_y][next_x] == BOARD::WALL) {
				continue;
			}

			if (distances[next_y][next_x] <= next_dist) {
				continue;
			}

			distances[next_y][next_x] = next_dist;
			q.push({ next_y, next_x, next_dist });
		}
	}

	const int no_sword_dist = distances[N - 1][M - 1];
	const int sword_dist = distances[sword_y][sword_x] + abs(N - sword_y - 1) + abs(M - sword_x - 1);
	const int result = min(no_sword_dist, sword_dist);

	if (result <= T) {
		printf("%d\n", result);
	}
	else {
		printf("Fail\n");
	}

	return 0;
}