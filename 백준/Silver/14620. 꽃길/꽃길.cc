#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int directions[5][2] = { {0, 0}, { 0, 1 }, {1, 0}, {-1, 0}, {0, -1} };

int N;
vector<vector<int>> prices;
int result = 987654321;

bool can_plant(const int y, const int x, const vector<vector<bool>>& board) {
	for (int i = 0; i < 5; ++i) {
		const int target_y = y + directions[i][0];
		const int target_x = x + directions[i][1];

		if (target_y < 0 || target_y >= N || target_x < 0 || target_x >= N) {
			return false;
		}

		if (board[target_y][target_x]) {
			return false;
		}
	}

	return true;
}

void plant(const int y, const int x, vector<vector<bool>>& board) {
	for (int i = 0; i < 5; ++i) {
		const int target_y = y + directions[i][0];
		const int target_x = x + directions[i][1];

		board[target_y][target_x] = true;
	}
}

void unplant(const int y, const int x, vector<vector<bool>>& board) {
	for (int i = 0; i < 5; ++i) {
		const int target_y = y + directions[i][0];
		const int target_x = x + directions[i][1];

		board[target_y][target_x] = false;
	}
}

int get_price(const int y, const int x) {
	int result = 0;
	for (int i = 0; i < 5; ++i) {
		const int target_y = y + directions[i][0];
		const int target_x = x + directions[i][1];

		result += prices[target_y][target_x];
	}

	return result;
}

void solve(vector<vector<bool>>& board, const int current_price = 0, const int plant_count = 0) {
	if (plant_count == 3) {
		result = min(result, current_price);
		return;
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (can_plant(y, x, board) == false) {
				continue;
			}

			plant(y, x, board);
			solve(board, current_price + get_price(y, x), plant_count + 1);
			unplant(y, x, board);
		}
	}
}

int main(void) {
	scanf("%d", &N);

	prices = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			scanf("%d", &prices[y][x]);
		}
	}

	vector<vector<bool>> board(N, vector<bool>(N, false));

	solve(board);

	printf("%d\n", result);

	return 0;
}