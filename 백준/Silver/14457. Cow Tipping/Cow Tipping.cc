#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Board;

constexpr int SLEEP = 1;
constexpr int WAKEUP = 0;

int N;
Board board;
int sleep_cow_count = 0;

void flip(Board& board, int target_y, int target_x) {
	for (int y = 0; y <= target_y; ++y) {
		for (int x = 0; x <= target_x; ++x) {
			board[y][x] = (board[y][x] + 1) % 2; // 0 -> 1, 1 -> 0

			if (board[y][x] == SLEEP) {
				++sleep_cow_count;
			}
			else {
				--sleep_cow_count;
			}
		}
	}
}

int main(void) {
	cin >> N;

	board = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			char c;
			cin >> c;
			board[y][x] = ((c == '1') ? SLEEP : WAKEUP);

			if (board[y][x] == 1) {
				++sleep_cow_count;
			}
		}
	}

	int result = 0; // flip count
	while (sleep_cow_count != 0) {
		for (int y = N - 1; y >= 0; --y) {
			for (int x = N - 1; x >= 0; --x) {
				if (board[y][x] == SLEEP) {
					flip(board, y, x);
					++result;
				}
			}
		}
	}

	cout << result;

	return 0;
}