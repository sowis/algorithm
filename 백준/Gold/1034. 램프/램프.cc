#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
vector<bool> row_visit;

bool row_validation(const vector<vector<bool>>& board, const int row) {
	int off_count = 0;
	for (int x = 0; x < M; ++x) {
		if (board[row][x] == 0) {
			++off_count;
		}
	}

	return (off_count <= K) && (((K - off_count) % 2) == 0);
}

int same_row_count(const vector<vector<bool>>& board, const int row) {
	int result = 0;
	for (int y = 0; y < N; ++y) {
		if (row_visit[y]) {
			continue;
		}

		bool same = true;
		for (int x = 0; x < M; ++x) {
			if (board[row][x] != board[y][x]) {
				same = false;
				break;
			}
		}

		if (same) {
			row_visit[row] = true;
			++result;
		}
	}

	return result;
}

int main(void) {
	cin >> N >> M;

	vector<vector<bool>> board(N, vector<bool>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char c;
			cin >> c;

			board[y][x] = (c == '1');
		}
	}

	cin >> K;

	row_visit = vector<bool>(N, false);
	int result = 0;

	for (int y = 0; y < N; ++y) {
		if (row_visit[y]) {
			continue;
		}

		if (row_validation(board, y) == false) {
			continue;
		}

		result = max(result, same_row_count(board, y));
	}

	cout << result;

	return 0;
}