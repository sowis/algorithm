#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
vector<vector<char>> board;

int min_same;

void check(const vector<int>& cols, const int y) {
	if (y <= 0) {
		return;
	}

	vector<vector<int>> same_cols(27);
	for (const int col : cols) {
		same_cols[board[y][col] - 'a'].push_back(col);
	}

	for (const vector<int>& next_cols : same_cols) {
		if (next_cols.size() < 2) {
			continue;
		}

		min_same = min(min_same, y);
		check(next_cols, y - 1);
	}
}


int main(void) {
	cin >> R >> C;
	board = vector<vector<char>>(R, vector<char>(C));

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cin >> board[y][x];
		}
	}

	min_same = R;
	vector<int> cols;
	for (int i = 0; i < C; ++i) {
		cols.push_back(i);
	}

	check(cols, R - 1);
	cout << min_same - 1;


	return 0;
}