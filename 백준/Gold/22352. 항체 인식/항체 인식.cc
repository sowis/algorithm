#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int N, M;
vector<int> union_find;
vector<vector<int>> before, after;

int uf_get_head(const int id) {
	if (union_find[id] == -1 || union_find[id] == id) {
		return union_find[id] = id;
	}

	return union_find[id] = uf_get_head(union_find[id]);
}

inline int uf_get_head(const int y, const int x) {
	return uf_get_head(y * M + x);
}

void uf_merge(const int id_1, const int id_2) {
	const int head_1 = uf_get_head(id_1);
	const int head_2 = uf_get_head(id_2);

	union_find[head_1] = head_2;
}

void uf_merge(const int y1, const int x1, const int y2, const int x2) {
	uf_merge(y1 * M + x1, y2 * M + x2);
}

int main(void) {
	cin >> N >> M;

	before = vector<vector<int>>(N, vector<int>(M));
	after = vector<vector<int>>(N, vector<int>(M));
	union_find = vector<int>(N * M, -1);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> before[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> after[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
					continue;
				}

				if (before[y][x] == before[next_y][next_x]) {
					uf_merge(y, x, next_y, next_x);
				}
			}
		}
	}

	unordered_set<int> change_heads;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (before[y][x] != after[y][x]) {
				change_heads.insert(uf_get_head(y, x));
			}
		}
	}

	if (change_heads.size() == 0) {
		cout << "YES\n";
		return 0;
	}

	if (change_heads.size() >= 2) {
		cout << "NO\n";
		return 0;
	}

	const int change_head = *change_heads.begin();
	int change_to = -1;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (uf_get_head(y, x) != change_head) {
				continue;
			}

			if (change_to == -1) {
				change_to = after[y][x];
				continue;
			}

			if (after[y][x] != change_to) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";

	return 0;
}