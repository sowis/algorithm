#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> board(2, vector<int>(N + 1, 1));
	for (int y = 0; y < 2; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> board[y][x];
		}
	}

	int result = 2;
	for (int x = 0; x < N; ++x) {
		if (board[0][x] == 1 && board[0][x + 1] == 1) {
			continue;
		}

		if (board[0][x] == 0 && board[1][x + 1] == 0) {
			result = 0;
			continue;
		}

		if (board[1][x] == 0 && board[0][x + 1] == 0) {
			result = 0;
			continue;
		}

		if (board[0][x] == 0 && board[1][x] == 0) {
			result = 0;
			continue;
		}

		result = min(result, 1);
	}

	cout << result;

	return 0;
}