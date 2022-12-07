#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

typedef unsigned int BitBoard;

BitBoard add(const BitBoard bb, const int y, const int x) {
	return bb | (1 << (y * 5 + x));
}

char board[5][5];
unordered_set<BitBoard> visit_bb;
unordered_set<BitBoard> results;
int result = 0;

void solve(const int y, const int x, const int y_count, const int s_count, const BitBoard bb) {
	visit_bb.insert(bb);

	if (y_count >= 4) {
		return;
	}

	if (y_count + s_count == 7) {
		results.insert(bb);
		return;
	}

	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			if ((bb & (1 << (y * 5 + x))) == 0) {
				continue;
			}

			for (int i = 0; i < 4; ++i) {
				const int next_y = y + directions[i][0];
				const int next_x = x + directions[i][1];

				if (next_y < 0 || next_y >= 5 || next_x < 0 || next_x >= 5) {
					continue;
				}

				const int next_y_count = (board[next_y][next_x] == 'Y') ? y_count + 1 : y_count;
				const int next_s_count = (board[next_y][next_x] == 'S') ? s_count + 1 : s_count;
				const BitBoard next_bb = add(bb, next_y, next_x);

				if (visit_bb.find(next_bb) != visit_bb.end()) {
					continue;
				}

				solve(next_y, next_x, next_y_count, next_s_count, next_bb);
			}
		}
	}
}

int main(void) {
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			solve(y, x, (board[y][x] == 'Y') ? 1 : 0, (board[y][x] == 'S') ?  1 : 0, add(0, y, x));
		}
	}

	cout << results.size();

	return 0;
}