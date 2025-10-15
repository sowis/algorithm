#include <iostream>
#include <vector>

using namespace std;

constexpr int SUDOKU_SIZE = 9;

typedef vector<vector<int>> Board;

bool is_valid_row(const Board& board, const int y) {
	vector<bool> exist(10, false);
	for (int x = 0; x < SUDOKU_SIZE; ++x) {
		if (exist[board[y][x]]) {
			return false;
		}

		exist[board[y][x]] = true;
	}

	return true;
}

bool is_valid_col(const Board& board, const int x) {
	vector<bool> exist(10, false);
	for (int y = 0; y < SUDOKU_SIZE; ++y) {
		if (exist[board[y][x]]) {
			return false;
		}

		exist[board[y][x]] = true;
	}

	return true;
}

bool is_valid_box(const Board& board, const int begin_y, const int begin_x) {
	vector<bool> exist(10, false);
	for (int y_offset = 0; y_offset < 3; ++y_offset) {
		for (int x_offset = 0; x_offset < 3; ++x_offset) {
			const int y = begin_y + y_offset;
			const int x = begin_x + x_offset;

			if (exist[board[y][x]]) {
				return false;
			}

			exist[board[y][x]] = true;
		}
	}

	return true;
}

bool is_valid(const Board& board) {
	for (int i = 0; i < SUDOKU_SIZE; ++i) {
		if (is_valid_row(board, i) == false) {
			return false;
		}

		if (is_valid_col(board, i) == false) {
			return false;
		}
	}

	for (int begin_y = 0; begin_y < SUDOKU_SIZE; begin_y += 3) {
		for (int begin_x = 0; begin_x < SUDOKU_SIZE; begin_x += 3) {
			if (is_valid_box(board, begin_y, begin_x) == false) {
				return false;
			}
		}
	}

	return true;
}

void test_case(void) {
	Board board(SUDOKU_SIZE, vector<int>(SUDOKU_SIZE));

	for (int y = 0; y < SUDOKU_SIZE; ++y) {
		for (int x = 0; x < SUDOKU_SIZE; ++x) {
			cin >> board[y][x];
		}
	}

	if (is_valid(board)) {
		cout << "CORRECT\n";
	}
	else {
		cout << "INCORRECT\n";
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cout << "Case " << i + 1 << ": ";
		test_case();
	}

	return 0;
}