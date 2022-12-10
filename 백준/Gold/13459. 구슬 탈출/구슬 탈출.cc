#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
constexpr pair<int, int> HOLE_IN{ -1, -1 };

int N, M;

void tilt(const vector<vector<char>>& board, pair<int, int>& blue, pair<int, int>& red, const int direction) {
	bool former_red = true;
	pair<int, int> former = red, latter = blue;

	switch (direction) {
	case 0:
		if (blue.second > red.second) {
			former_red = false;
			swap(former, latter);
		}
		break;
	case 1:
		if (blue.second < red.second) {
			former_red = false;
			swap(former, latter);
		}
		break;
	case 2:
		if (blue.first > red.first) {
			former_red = false;
			swap(former, latter);
		}
		break;
	case 3:
		if (blue.first < red.first) {
			former_red = false;
			swap(former, latter);
		}
		break;
	}

	while (true) {
		const int next_y = former.first + directions[direction][0];
		const int next_x = former.second + directions[direction][1];

		if (board[next_y][next_x] == '#') {
			break;
		}

		former = { next_y, next_x };

		if (board[next_y][next_x] == 'O') {
			former = HOLE_IN;
			break;
		}
	}

	while (true) {
		const int next_y = latter.first + directions[direction][0];
		const int next_x = latter.second + directions[direction][1];

		if (board[next_y][next_x] == '#') {
			break;
		}

		if (former.first == next_y && former.second == next_x) {
			break;
		}

		latter = { next_y, next_x };

		if (board[next_y][next_x] == 'O') {
			latter = HOLE_IN;
			break;
		}
	}

	if (former_red) {
		red = former;
		blue = latter;
	}
	else {
		red = latter;
		blue = former;
	}
}

bool solve(const vector<vector<char>>& board, const pair<int, int>& blue, const pair<int, int>& red, const int move_count) {
	if (move_count == 10) {
		return false;
	}

	for (int direction = 0; direction < 4; ++direction) {
		pair<int, int> next_blue = blue;
		pair<int, int> next_red = red;

		tilt(board, next_blue, next_red, direction);

		if (next_blue == HOLE_IN) {
			continue;
		}

		if (next_red == HOLE_IN) {
			return true;
		}

		if (solve(board, next_blue, next_red, move_count + 1) == true) {
			return true;
		}
	}

	return false;
}

int main(void) {
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));
	pair<int, int> blue, red;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];

			if (board[y][x] == 'B') {
				blue.first = y;
				blue.second = x;
				board[y][x] = '.';
			}
			else if (board[y][x] == 'R') {
				red.first = y;
				red.second = x;
				board[y][x] = '.';
			}
		}
	}

	const bool result = solve(board, blue, red, 0);

	cout << (result ? 1 : 0) << "\n";

	return 0;
}