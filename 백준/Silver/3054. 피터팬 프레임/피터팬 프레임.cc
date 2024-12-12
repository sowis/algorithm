#include <iostream>
#include <string>
#include <vector>

using namespace std;

void paint(vector<vector<char>>& board, const int begin_x, const char c, const char frame) {
	for (int y = 0; y < 5; ++y) {
		for (int x = begin_x; x < begin_x + 5; ++x) {
			board[y][x] = '.';
		}
	}

	board[0][begin_x + 2] = frame;
	board[1][begin_x + 1] = frame;
	board[1][begin_x + 3] = frame;
	board[2][begin_x + 0] = frame;
	board[2][begin_x + 2] = c;
	board[2][begin_x + 4] = frame;
	board[3][begin_x + 1] = frame;
	board[3][begin_x + 3] = frame;
	board[4][begin_x + 2] = frame;
}

int main(void) {
	string str;
	cin >> str;

	vector<vector<char>> board(5, vector<char>(str.size() * 4 + 1));
	for (int i = 0; i < str.size(); ++i) {
		paint(board, i * 4, str[i], '#');
	}

	for (int i = 0; i < str.size(); ++i) {
		if ((i + 1) % 3 == 0) {
			paint(board, i * 4, str[i], '*');
		}
	}

	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < str.size() * 4 + 1; ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}