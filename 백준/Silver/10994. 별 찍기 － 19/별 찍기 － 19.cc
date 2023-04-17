#include <iostream>
#include <vector>

using namespace std;

void square(vector<vector<char>>& board, const int begin_y, const int begin_x, const int width) {
	for (int x = begin_x; x < begin_x + width; ++x) {
		board[begin_y][x] = '*';
		board[begin_y + width - 1][x] = '*';
	}

	for (int y = begin_y; y < begin_y + width; ++y) {
		board[y][begin_x] = '*';
		board[y][begin_x + width - 1] = '*';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	const int sz = 1 + ((N - 1) * 4);
	vector<vector<char>> board(sz, vector<char>(sz, ' '));

	int begin_y = sz / 2;
	int begin_x = sz / 2;
	int width = 1;

	for (int i = 1; i <= N; ++i) {
		square(board, begin_y, begin_x, width);
		begin_y -= 2;
		begin_x -= 2;
		width += 4;
	}

	for (int y = 0; y < sz; ++y) {
		for (int x = 0; x < sz; ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}