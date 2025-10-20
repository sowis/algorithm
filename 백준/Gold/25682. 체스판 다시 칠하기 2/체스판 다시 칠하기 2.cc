#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> board;
vector<vector<int>> clear_board;
vector<vector<int>> psum;

int get_change(const int y, const int begin_x, const int end_x) { // [begin_x, end_x)
	if (begin_x == 0) {
		return psum[y][end_x - 1];
	}

	return psum[y][end_x - 1] - psum[y][begin_x - 1];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char c;
			cin >> c;

			board[y][x] = (c == 'B') ? 1 : 0;
		}
	}

	clear_board = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			clear_board[y][x] = (y + x) % 2;
		}
	}

	psum = vector<vector<int>>(N, vector<int>(M, 0));
	for (int y = 0; y < N; ++y) {
		int cur = 0;
		for (int x = 0; x < M; ++x) {
			cur += (board[y][x] != clear_board[y][x]) ? 1 : 0;
			psum[y][x] = cur;
		}
	}

	int result = 1987654321;
	for (int x = 0; x < M; ++x) {
		if (M < x + K) {
			break;
		}

		int change_count = -1;
		for (int y = 0; y < N; ++y) {
			if (N < y + K) {
				break;
			}

			if (change_count == -1) {
				change_count = 0;
				for (int y_offset = 0; y_offset < K; ++y_offset) {
					change_count += get_change(y + y_offset, x, x + K);
				}
			}
			else {
				change_count -= get_change(y - 1, x, x + K);
				change_count += get_change(y - 1 + K, x, x + K);
			}

			result = min(result, min(change_count, K * K - change_count));
		}
	}

	cout << result;

	return 0;
}