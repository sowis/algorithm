#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int EMPTY = 0;
constexpr int WALL = 1;
constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

typedef struct {
	int y;
	int x;
	int dist;
} Data;

int N, M;
int H, W;
int src_y, src_x;
int dst_y, dst_x;
vector<vector<int>> board;
vector<vector<int>> min_dist;
queue<Data> q;

bool can_move(const int y, const int x, const int direction) {
	if (direction == 0) {
		if (x + W >= M) {
			return false;
		}

		for (int next_y = y; next_y < y + H; ++next_y) {
			if (board[next_y][x + W] == WALL) {
				return false;
			}
		}
	}
	else if (direction == 1) {
		if (y + H >= N) {
			return false;
		}

		for (int next_x = x; next_x < x + W; ++next_x) {
			if (board[y + H][next_x] == WALL) {
				return false;
			}
		}
	}
	else if (direction == 2) {
		if (y == 0) {
			return false;
		}

		for (int next_x = x; next_x < x + W; ++next_x) {
			if (board[y - 1][next_x] == WALL) {
				return false;
			}
		}
	}
	else {
		if (x == 0) {
			return false;
		}

		for (int next_y = y; next_y < y + H; ++next_y) {
			if (board[next_y][x - 1] == WALL) {
				return false;
			}
		}
	}

	return true;
}

int main(void) {
	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	cin >> H >> W >> src_y >> src_x >> dst_y >> dst_x;
	/* 0부터 시작하도록 */
	--src_y;
	--src_x;
	--dst_y;
	--dst_x;
	/********************/

	min_dist = vector<vector<int>>(N, vector<int>(M, 1987654321));
	min_dist[src_y][src_x] = 0;
	q.push({ src_y, src_x, 0 });

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		if (d.dist != min_dist[d.y][d.x]) {
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			if (can_move(d.y, d.x, i) == false) {
				continue;
			}

			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];
			const int next_distance = d.dist + 1;

			if (min_dist[next_y][next_x] <= next_distance) {
				continue;
			}

			min_dist[next_y][next_x] = next_distance;
			q.push({ next_y, next_x, next_distance });
		}
	}

	const int result = (min_dist[dst_y][dst_x] == 1987654321) ? -1 : min_dist[dst_y][dst_x];
	cout << result;

	return 0;
}