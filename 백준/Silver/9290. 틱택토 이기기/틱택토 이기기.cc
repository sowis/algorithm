#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Board;

bool is_win(const Board& board, const char me) {
	for (int y = 0; y < 3; ++y) {
		bool win = true;
		for (int x = 0; x < 3; ++x) {
			if (board[y][x] != me) {
				win = false;
				break;
			}
		}

		if (win) {
			return true;
		}
	}

	for (int x = 0; x < 3; ++x) {
		bool win = true;
		for (int y = 0; y < 3; ++y) {
			if (board[y][x] != me) {
				win = false;
				break;
			}
		}

		if (win) {
			return true;
		}
	}

	bool win = true;
	for (int i = 0; i < 3; ++i) {
		if (board[i][i] != me) {
			win = false;
			break;
		}
	}

	if (win) {
		return true;
	}

	win = true;
	for (int i = 0; i < 3; ++i) {
		if (board[i][2 - i] != me) {
			win = false;
			break;
		}
	}

	if (win) {
		return true;
	}

	return false;
}

void test_case(const int case_id) {
	Board board(3, vector<char>(3));
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			cin >> board[y][x];
		}
	}

	char me;
	cin >> me;

	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			if (board[y][x] != '-') {
				continue;
			}

			const char backup = board[y][x];
			board[y][x] = me;
			if (is_win(board, me)) {
				cout << "Case " << case_id << ":\n";
				for (int i = 0; i < 3; ++i) {
					for (int k = 0; k < 3; ++k) {
						cout << board[i][k];
					}
					cout << "\n";
				}

				return;
			}
			board[y][x] = backup;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case(i + 1);
	}

	return 0;
}