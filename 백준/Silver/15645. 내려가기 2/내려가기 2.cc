#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[3] = { -1, 0, 1 };

int N;
vector<vector<int>> board;
vector<vector<int>> max_score;
vector<vector<int>> min_score;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	board = vector<vector<int>>(N, vector<int>(3));
	min_score = vector<vector<int>>(N, vector<int>(3, 1987654321));
	max_score = vector<vector<int>>(N, vector<int>(3, -1));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < 3; ++x) {
			cin >> board[y][x];
		}
	}

	for (int x = 0; x < 3; ++x) {
		min_score[0][x] = board[0][x];
		max_score[0][x] = board[0][x];
	}

	for (int y = 0; y < N - 1; ++y) {
		for (int x = 0; x < 3; ++x) {
			for (int i = 0; i < 3; ++i) {
				const int next_y = y + 1;
				const int next_x = x + directions[i];

				if (next_x < 0 || next_x >= 3) {
					continue;
				}

				const int next_min = min_score[y][x] + board[next_y][next_x];
				min_score[next_y][next_x] = min(min_score[next_y][next_x], next_min);

				const int next_max = max_score[y][x] + board[next_y][next_x];
				max_score[next_y][next_x] = max(max_score[next_y][next_x], next_max);
			}
		}
	}

	int max_result = 0;
	int min_result = 198654321;
	for (int x = 0; x < 3; ++x) {
		max_result = max(max_result, max_score[N - 1][x]);
		min_result = min(min_result, min_score[N - 1][x]);
	}

	cout << max_result << " " << min_result;

	return 0;
}