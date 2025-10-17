#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	vector<vector<int>> psum(N, vector<int>(M));
	psum[0][0] = board[0][0];

	for (int y = 1; y < N; ++y) {
		psum[y][0] = psum[y - 1][0] + board[y][0];
	}

	for (int x = 1; x < M; ++x) {
		psum[0][x] = psum[0][x - 1] + board[0][x];
	}

	for (int y = 1; y < N; ++y) {
		for (int x = 1; x < M; ++x) {
			psum[y][x] = board[y][x] + psum[y - 1][x] + psum[y][x - 1] - psum[y - 1][x - 1];
		}
	}

	int result = -1987654321;
	for (int begin_y = 0; begin_y < N; ++begin_y) {
		for (int begin_x = 0; begin_x < M; ++begin_x) {
			for (int end_y = begin_y; end_y < N; ++end_y) {
				for (int end_x = begin_x; end_x < M; ++end_x) {
					const int left = (begin_x == 0) ? 0 : psum[end_y][begin_x - 1];
					const int up = (begin_y == 0) ? 0 : psum[begin_y - 1][end_x];
					const int left_up = ((begin_x == 0) || (begin_y == 0)) ? 0 : psum[begin_y - 1][begin_x - 1];
					result = max(result, psum[end_y][end_x] - left - up + left_up);
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}