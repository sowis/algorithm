#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

typedef unsigned int KEYS;

typedef struct {
	int y;
	int x;
	KEYS keys;
	int move_count;
} Data;

int N, M;
char board[50][50];
int visit[1 << 7][50][50];
int begin_y, begin_x;
vector<pair<int, int>> end_points;

void get_key(KEYS& keys, const char key) {
	keys |= 1 << (key - 'a');
}

bool can_open(const KEYS keys, const char door) {
	return keys & (1 << (door - 'A'));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < (1 << 7); ++i) {
		for (int y = 0; y < 50; ++y) {
			for (int x = 0; x < 50; ++x) {
				visit[i][y][x] = numeric_limits<int>::max();
			}
		}
	}

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];

			if (board[y][x] == '0') {
				begin_y = y;
				begin_x = x;
			}
			else if (board[y][x] == '1') {
				end_points.push_back({ y, x });
			}
		}
	}

	queue<Data> q;
	q.push({ begin_y, begin_x, 0, 0 });
	visit[0][begin_y][begin_x] = 0;

	while (q.empty() == false) {
		const Data d = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			const int next_y = d.y + directions[i][0];
			const int next_x = d.x + directions[i][1];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
				continue;
			}

			if (board[next_y][next_x] == '#') {
				continue;
			}

			if ('A' <= board[next_y][next_x] && board[next_y][next_x] <= 'F') {
				if (can_open(d.keys, board[next_y][next_x]) == false) {
					continue;
				}
			}

			KEYS next_keys = d.keys;
			if ('a' <= board[next_y][next_x] && board[next_y][next_x] <= 'f') {
				get_key(next_keys, board[next_y][next_x]);
			}

			const int next_move_count = d.move_count + 1;
			if (visit[next_keys][next_y][next_x] <= next_move_count) {
				continue;
			}

			visit[next_keys][next_y][next_x] = next_move_count;
			q.push({ next_y, next_x, next_keys, next_move_count });
		}
	}

	int result = numeric_limits<int>::max();
	for (const pair<int, int>& end_point : end_points) {
		for (int i = 0; i < (1 << 7); ++i) {
			result = min(result, visit[i][end_point.first][end_point.second]);
		}
	}

	cout << ((result == numeric_limits<int>::max()) ? -1 : result) << "\n";

	return 0;
}