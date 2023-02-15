#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

char board[5][5];
unordered_set<string> result;

void solve(const int y, const int x, const string& number) {
	if (number.size() == 6) {
		result.insert(number);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= 5 || next_x < 0 || next_x >= 5) {
			continue;
		}

		solve(next_y, next_x, number + board[next_y][next_x]);
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
			solve(y, x, string{ board[y][x] });
		}
	}

	cout << result.size();

	return 0;
}