#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[3][2] = { {-1, -1}, {-1, 0}, {0, -1} };

vector<int> segtree;

int segtree_add(const int begin, const int end, const int target_begin, const int target_end, const int value, const int idx = 1) {
	if (end <= target_begin || target_end <= begin) {
		return 0;
	}

	if (end - begin == 1) {
		segtree[idx] += value;
		return segtree[idx];
	}

	const int mid = (begin + end) / 2;
	const int left = segtree_add(begin, mid, target_begin, target_end, value, idx * 2);
	const int right = segtree_add(mid, end, target_begin, target_end, value, idx * 2 + 1);
	return segtree[idx] = left + right;
}

int segtree_get(const int begin, const int end, const int target_begin, const int target_end, const int idx = 1) {
	if (end <= target_begin || target_end <= begin) {
		return 0;
	}

	if (target_begin <= begin && end <= target_end) {
		return segtree[idx];
	}

	const int mid = (begin + end) / 2;
	const int left = segtree_get(begin, mid, target_begin, target_end, idx * 2);
	const int right = segtree_get(mid, end, target_begin, target_end, idx * 2 + 1);
	return left + right;
}

int segtree_get(const int begin, const int end, const int target, const int idx = 1) {
	return segtree_get(begin, end, target, target + 1, idx);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M, N;
	cin >> M >> N;

	segtree = vector<int>(2 * M * 5, 1);
	for (int i = 0; i < N; ++i) {
		int count_0, count_1, count_2;
		cin >> count_0 >> count_1 >> count_2;

		segtree_add(0, 2 * M, count_0, count_0 + count_1, 1);
		segtree_add(0, 2 * M, count_0 + count_1, count_0 + count_1 + count_2, 2);
	}

	vector<vector<int>> board(M, vector<int>(M, 0));
	int segtree_index = 0;
	for (int y = M - 1; y >= 0; --y) {
		board[y][0] = segtree_get(0, 2 * M, segtree_index);
		++segtree_index;
	}

	for (int x = 1; x < M; ++x) {
		board[0][x] = segtree_get(0, 2 * M, segtree_index);
		++segtree_index;
	}

	for (int y = 1; y < M; ++y) {
		for (int x = 1; x < M; ++x) {
			for (int i = 0; i < 3; ++i) {
				const int last_y = y + directions[i][0];
				const int last_x = x + directions[i][1];

				board[y][x] = max(board[y][x], board[last_y][last_x]);
			}
		}
	}

	for (int y = 0; y < M; ++y) {
		for (int x = 0; x < M; ++x) {
			cout << board[y][x] << " ";
		}

		cout << "\n";
	}

	return 0;
}