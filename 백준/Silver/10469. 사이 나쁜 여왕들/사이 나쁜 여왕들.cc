#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
constexpr char QUEEN = '*';

char board[8][8];

bool is_valid_queen(const int y, const int x) {
	for (int i = 0; i < 8; ++i) {
		for (int dist = 1; ; ++dist) {
			const int next_y = y + dist * directions[i][0];
			const int next_x = x + dist * directions[i][1];

			if (next_y < 0 || next_y >= 8 || next_x < 0 || next_x >= 8) {
				break;
			}

			if (board[next_y][next_x] == QUEEN) {
				return false;
			}
		}
	}

	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int y = 0; y < 8; ++y) {
		for (int x = 0; x < 8; ++x) {
			cin >> board[y][x];
		}
	}

	int queen_count = 0;
	for (int y = 0; y < 8; ++y) {
		for (int x = 0; x < 8; ++x) {
			if (board[y][x] != QUEEN) {
				continue;
			}

			++queen_count;
			if (is_valid_queen(y, x) == false) {
				cout << "invalid";
				return 0;
			}
		}
	}

	if (queen_count != 8) {
		cout << "invalid";
		return 0;
	}

	cout << "valid";

	return 0;
}