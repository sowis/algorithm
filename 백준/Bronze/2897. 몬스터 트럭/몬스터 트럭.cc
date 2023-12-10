#include <iostream>
#include <vector>
#include <string>

using namespace std;

int break_count(const vector<vector<char>>& board, const int begin_y, const int begin_x) {
	int result = 0;
	for (int y = begin_y; y < begin_y + 2; ++y) {
		for (int x = begin_x; x < begin_x + 2; ++x) {
			if (board[y][x] == '#') {
				return -1;
			}

			if (board[y][x] == 'X') {
				++result;
			}
		}
	}

	return result;
}

int main(void) {
	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R, vector<char>(C));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];
		}
	}

	vector<int> break_counts(5, 0);
	for (int y = 0; y < R - 1; ++y) {
		for (int x = 0; x < C - 1; ++x) {
			const int count = break_count(board, y, x);
			if (count == -1) {
				continue;
			}

			++break_counts[count];
		}
	}

	for (int i = 0; i < 5; ++i) {
		cout << break_counts[i] << "\n";
	}

	return 0;
}