#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[9][2] = { {0, -1}, {0, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 0}, {1, 1 } };

vector<vector<char>> board(4, vector<char>(10));
vector<char> hits(9);

bool is_hit(const int y, const int x) {
	for (const int h : hits) {
		bool find = false;
		for (int i = 0; i < 9; ++i) {
			const int next_y = y + directions[i][0];
			const int next_x = x + directions[i][1];

			if (board[next_y][next_x] == h) {
				find = true;
				break;
			}
		}

		if (find == false) {
			return false;
		}
	}

	return true;
}

int main(void) {
	for (int y = 0; y < 4; ++y) {
		for (int x = 0; x < 10; ++x) {
			cin >> board[y][x];
		}
	}

	for (char& c : hits) {
		cin >> c;
	}

	for (int y = 1; y < 3; ++y) {
		for (int x = 1; x < 9; ++x) {
			if (is_hit(y, x)) {
				cout << board[y][x];
				return 0;
			}
		}
	}

	return 0;
}