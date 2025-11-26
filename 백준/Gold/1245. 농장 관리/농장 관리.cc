#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

constexpr int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

int N, M;
vector<vector<int>> board;
vector<int> union_find;

int uf_get_head(const int id) {
	if (union_find[id] == id || union_find[id] == -1) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

int uf_get_head(const int y, const int x) {
	const int id = y * M + x;
	return uf_get_head(id);
}

void uf_merge(const int id_1, const int id_2) {
	const int head_1 = uf_get_head(id_1);
	const int head_2 = uf_get_head(id_2);

	union_find[head_1] = head_2;
}

void uf_merge(const int y1, const int x1, const int y2, const int x2) {
	uf_merge(y1 * M + x1, y2 * M + x2);
}

void uf_tie(const int y, const int x) {
	for (int i = 0; i < 8; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (board[y][x] != board[next_y][next_x]) {
			continue;
		}

		if (uf_get_head(y, x) == uf_get_head(next_y, next_x)) {
			continue;
		}

		uf_merge(y, x, next_y, next_x);
		uf_tie(next_y, next_x);
	}
}

bool is_top(const int y, const int x) {
	for (int i = 0; i < 8; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (board[y][x] < board[next_y][next_x]) {
			return false;
		}
	}

	return true;
}

bool is_top_all(const int head_id) {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (uf_get_head(y, x) != head_id) {
				continue;
			}

			if (is_top(y, x) == false) {
				return false;
			}
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(M));

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	union_find = vector<int>(N * M + 1, -1);
	for (int y = 0; y < N; ++y) { // 높이가 같고 인접한 곳끼리 묶기
		for (int x = 0; x < M; ++x) {
			uf_tie(y, x);
		}
	}

	unordered_set<int> checked_head;
	int result = 0;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			const int target_head = uf_get_head(y, x);
			if (checked_head.find(target_head) != checked_head.end()) {
				continue;
			}

			checked_head.insert(target_head);
			if (is_top_all(target_head)) {
				++result;
			}
		}
	}

	cout << result;

	return 0;
}