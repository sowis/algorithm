#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> board(H, vector<char>(W));
	vector<vector<int>> result(H, vector<int>(W, -1));
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			cin >> board[y][x];
		}
	}

	for (int t = 0; t < W; ++t) {
		for (int origin_x = 0; origin_x < W; ++origin_x) {
			const int move_x = origin_x + t;
			if (move_x >= W) {
				break;
			}

			for (int y = 0; y < H; ++y) {
				if (board[y][origin_x] != 'c') {
					continue;
				}

				if (result[y][move_x] != -1) {
					continue;
				}

				result[y][move_x] = t;
			}
		}
	}

	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			cout << result[y][x] << " ";
		}

		cout << "\n";
	}

	return 0;
}