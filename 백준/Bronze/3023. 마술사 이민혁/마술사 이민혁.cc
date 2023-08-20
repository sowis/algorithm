#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int R, C;
	cin >> R >> C;

	vector<vector<char>> board(R * 2, vector<char>(C * 2));
	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];
			board[y][2 * C - 1 - x] = board[y][x];
		}
	}

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < 2 * C; ++x) {
			board[2 * R - 1 - y][x] = board[y][x];
		}
	}

	int a, b;
	cin >> a >> b;

	board[a - 1][b - 1] = (board[a - 1][b - 1] == '.') ? '#' : '.';

	for (int y = 0; y < 2 * R; ++y) {
		for (int x = 0; x < 2 * C; ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}