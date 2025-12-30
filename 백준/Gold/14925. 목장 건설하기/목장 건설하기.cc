#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> max_y, max_x, max_block;

int main(void) {
	int N, M;
	cin >> N >> M;

	board = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	max_y = vector<vector<int>>(N, vector<int>(M, 0));
	max_x = vector<vector<int>>(N, vector<int>(M, 0));

	for (int y = 0; y < N; ++y) {
		int cur = 0;
		for (int x = 0; x < M; ++x) {
			if (board[y][x] == 0) {
				++cur;
			}
			else {
				cur = 0;
			}

			max_x[y][x] = cur;
		}
	}

	for (int x = 0; x < M; ++x) {
		int cur = 0;
		for (int y = 0; y < N; ++y) {
			if (board[y][x] == 0) {
				++cur;
			}
			else {
				cur = 0;
			}

			max_y[y][x] = cur;
		}
	}

	int result = 0;
	max_block = vector<vector<int>>(N, vector<int>(M, 0));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (y == 0 || x == 0) {
				max_block[y][x] = min(max_y[y][x], max_x[y][x]);
			}
			else {
				max_block[y][x] = min(max_block[y - 1][x - 1] + 1, min(max_y[y][x], max_x[y][x]));
			}

			result = max(result, max_block[y][x]);
		}
	}

	cout << result;

	return 0;
}