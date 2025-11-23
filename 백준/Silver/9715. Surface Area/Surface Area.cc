#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void test_case(void) {
	int R, C;
	cin >> R >> C;

	vector<vector<int>> board(R, vector<int>(C));
	vector<vector<int>> contact(R, vector<int>(C, 0));
	int all_surface = 0;
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			char num;
			cin >> num;

			board[y][x] = num - '0';
			all_surface += 6 * board[y][x];
			contact[y][x] += max(0, 2 * (board[y][x] - 1)); // 위아래 접촉면 수
		}
	}

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= R || next_x < 0 || next_x >= C) {
					continue;
				}

				contact[y][x] += min(board[y][x], board[next_y][next_x]); // 옆방향 접촉면 수
			}
		}
	}

	int result = all_surface;
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			result -= contact[y][x]; // 모든 면 수에서 접촉면 수를 뺌
		}
	}

	cout << result << "\n";
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