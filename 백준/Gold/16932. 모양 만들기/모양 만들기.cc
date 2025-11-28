#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N, M;
vector<vector<int>> board;
vector<int> union_find;

int uf_get_head(const int id) {
	if (union_find[id] == -1 || union_find[id] == id) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

void uf_merge(const int id1, const int id2) {
	const int head1 = uf_get_head(id1);
	const int head2 = uf_get_head(id2);

	union_find[head1] = head2;
}

void uf_bind(const int y, const int x) {
	for (int i = 0; i < 4; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (board[y][x] != board[next_y][next_x]) {
			continue;
		}

		if (uf_get_head(y * M + x) == uf_get_head(next_y * M + next_x)) {
			continue;
		}

		uf_merge(y * M + x, next_y * M + next_x);
		uf_bind(next_y, next_x);
	}
}

int main(void) {
	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	union_find = vector<int>(N * M, -1);

	for (int y = 0; y < N; ++y) { // 그룹 묶기
		for (int x = 0; x < M; ++x) {
			if (board[y][x] == 0) {
				continue;
			}

			uf_bind(y, x);
		}
	}

	unordered_map<int, int> group_size;
	for (int y = 0; y < N; ++y) { // 그룹별로 크기 구하기
		for (int x = 0; x < M; ++x) {
			++group_size[uf_get_head(y * M + x)];
		}
	}

	int result = 0;
	for (int y = 0; y < N; ++y) { // 하나 변경했을때 합쳐진 그룹 크기가 가장 큰 것 구하기
		for (int x = 0; x < M; ++x) {
			if (board[y][x] != 0) {
				continue;
			}

			unordered_set<int> anothers;
			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
					continue;
				}

				if (board[next_y][next_x] == 0) {
					continue;
				}

				anothers.insert(uf_get_head(next_y * M + next_x));
			}

			int merged_group_size = 1; // 자기자신 1
			for (const int id : anothers) {
				merged_group_size += group_size[id];
			}

			result = max(result, merged_group_size);
		}
	}

	cout << result << "\n";

	return 0;
}