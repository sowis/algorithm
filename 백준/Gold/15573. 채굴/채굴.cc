#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
constexpr int AIR = -1;
constexpr int GROUND = 1987654321;

typedef struct _data {
	int y;
	int x;
	int s;

	bool operator<(const struct _data& d) const {
		return this->s > d.s;
	}
} Data;

int N, M, K;
vector<vector<int>> board;

int main(void) {
	cin >> N >> M >> K;

	board = vector<vector<int>>(N + 2, vector<int>(M + 2, AIR));
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int x = 0; x < M + 2; ++x) {
		board[N + 1][x] = GROUND; // 바닥 (채굴불가)
	}

	priority_queue<Data> q;
	vector<vector<bool>> target_check(N + 2, vector<bool>(M + 2, false));
	for (int x = 1; x < M + 1; ++x) {
		q.push({ 1, x, board[1][x] });
		target_check[1][x] = true;
	}

	for (int y = 1; y < N + 1; ++y) {
		if (target_check[y][1] == false) {
			q.push({ y, 1, board[y][1] });
			target_check[y][1] = true;
		}

		if (target_check[y][M] == false) {
			q.push({ y, M, board[y][M] });
			target_check[y][M] = true;
		}
	}

	int mine_count = 0;
	int result = -1;
	while (q.empty() == false) {
		const Data d = q.top();
		q.pop();

		if (board[d.y][d.x] == AIR) { // 이미 채굴한거면 넘기기
			continue;
		}

		++mine_count;
		board[d.y][d.x] = AIR;
		result = max(result, d.s); // 채굴했던 가장 단단한 광물
		if (mine_count >= K) {
			cout << result;
			return 0;
		}

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (board[next_y][next_x] == AIR || board[next_y][next_x] == GROUND) {
				continue;
			}

			if (target_check[next_y][next_x]) {
				continue;
			}

			q.push({ next_y, next_x, board[next_y][next_x] });
			target_check[next_y][next_x] = true;
		}
	}

	return 0;
}