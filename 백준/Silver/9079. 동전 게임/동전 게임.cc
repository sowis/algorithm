#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int reverse_table[8][3][2] = {{{0, 0}, {0, 1}, {0, 2}},
	{{1, 0}, {1, 1}, {1, 2}},
	{{2, 0}, {2, 1}, {2, 2}},
	{{0, 0}, {1, 0}, {2, 0}},
	{{0, 1}, {1, 1}, {2, 1}},
	{{0, 2}, {1, 2}, {2, 2}},
	{{0, 0}, {1, 1}, {2, 2}},
	{{2, 0}, {1, 1}, {0, 2}}
};

constexpr int H = 1;
constexpr int T = -1;

bool is_all_same(const vector<vector<int>>& board, const vector<vector<int>> &reverse_target) {
	const int target = board[0][0] * reverse_target[0][0];
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			if (board[y][x] * reverse_target[y][x] != target) {
				return false;
			}
		}
	}

	return true;
}

void test_case(void) {
	vector<vector<int>> board(3, vector<int>(3));
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			char op;
			cin >> op;

			if (op == 'H') {
				board[y][x] = H;
			}
			else {
				board[y][x] = T;
			}
		}
	}

	int min_reverse = 1987654321;
	for (int reverse_vector = 0; reverse_vector < 256; ++reverse_vector) {
		int reverse_count = 0;
		vector<vector<int>> reverse_target(3, vector<int>(3, 1));

		for (int i = 0; i < 8; ++i) {
			if ((1 << i) & reverse_vector) {
				++reverse_count;
				for (int k = 0; k < 3; ++k) {
					const int target_y = reverse_table[i][k][0];
					const int target_x = reverse_table[i][k][1];
					reverse_target[target_y][target_x] *= -1;
				}
			}
		}

		if (is_all_same(board, reverse_target)) {
			min_reverse = min(min_reverse, reverse_count);
		}
	}

	if (min_reverse == 1987654321) {
		min_reverse = -1;
	}

	cout << min_reverse << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}