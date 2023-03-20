#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

typedef struct _log {
	int y;
	int x;
	int d;

	bool operator==(const _log& other) const {
		return y == other.y && x == other.x && d == other.d;
	}
} Log;

struct hash_fn {
	size_t operator() (const Log& log) const {
		return (log.y << 20) || (log.x << 10) || log.d;
	}
};

int N;
vector<vector<char>> board;
Log source;
Log target;

unordered_map<Log, int, hash_fn> cache;

inline Log move(const Log& current, const int direction) {
	return { current.y + directions[direction][0], current.x + directions[direction][1], current.d };
}

bool can_turn(const Log& current, const vector<vector<char>>& board) {
	const int mid_y = current.y + directions[current.d][0];
	const int mid_x = current.x + directions[current.d][1];

	for (int y = mid_y - 1; y <= mid_y + 1; ++y) {
		for (int x = mid_x - 1; x <= mid_x + 1; ++x) {
			if (y < 0 || y >= N || x < 0 || x >= N) {
				return false;
			}

			if (board[y][x] == '1') {
				return false;
			}
		}
	}

	return true;
}

Log turn(const Log& current) {
	if (current.d == 0) {
		return { current.y - 1, current.x + 1, 1 };
	}
	else {
		return { current.y + 1, current.x - 1, 0 };
	}
}

bool conflict(const Log &log, const vector<vector<char>> &board) {
	for (int hop = 0; hop < 3; ++hop) {
		const int y = log.y + (directions[log.d][0] * hop);
		const int x = log.x + (directions[log.d][1] * hop);

		if (y < 0 || y >= N || x < 0 || x >= N) {
			return true;
		}

		if (board[y][x] == '1') {
			return true;
		}
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	board = vector<vector<char>>(N, vector<char>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y][x] == 'B') {
				if (y + 1 < N && board[y + 1][x] == 'B') {
					source = { y, x, 1 };
					board[y][x] = '0';
					board[y + 1][x] = '0';
					board[y + 2][x] = '0';
				}
				else {
					source = { y, x, 0 };
					board[y][x] = '0';
					board[y][x + 1] = '0';
					board[y][x + 2] = '0';
				}
			}

			if (board[y][x] == 'E') {
				if (y + 1 < N && board[y + 1][x] == 'E') {
					target = { y, x, 1 };
					board[y][x] = '0';
					board[y + 1][x] = '0';
					board[y + 2][x] = '0';
				}
				else {
					target = { y, x, 0 };
					board[y][x] = '0';
					board[y][x + 1] = '0';
					board[y][x + 2] = '0';
				}
			}
		}
	}

	queue<Log> q;
	q.push(source);
	cache[source] = 0;

	while (q.empty() == false) {
		const Log current = q.front();
		q.pop();

		/* 이동 */
		for (int d = 0; d < 4; ++d) {
			const Log next = move(current, d);
			if (conflict(next, board)) {
				continue;
			}

			if (cache.find(next) != cache.end()) {
				continue;
			}

			cache[next] = cache[current] + 1;
			q.push(next);
		}
		/*******/

		/* 회전 */
		if (can_turn(current, board) == false) {
			continue;
		}

		const Log next = turn(current);
		if (conflict(next, board)) {
			continue;
		}

		if (cache.find(next) != cache.end()) {
			continue;
		}

		cache[next] = cache[current] + 1;
		q.push(next);
		/*******/
	}

	if (cache.find(target) == cache.end()) {
		cout << "0\n";
	}
	else {
		cout << cache[target] << "\n";
	}

	return 0;
}