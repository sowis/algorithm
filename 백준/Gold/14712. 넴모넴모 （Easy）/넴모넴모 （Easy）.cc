#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[3][2] = { {-1, -1}, {-1, 0}, {0, -1} };

int N, M;
int result = 0;
vector<vector<bool>> board;

void backtracking(const int id) {
	const int y = id / M;
	const int x = id % M;

	if (id == N * M) {
		++result;
		return;
	}

	bool can_put_nemo = false;
	for (int i = 0; i < 3; ++i) {
		const int last_y = y + directions[i][0];
		const int last_x = x + directions[i][1];

		if (last_y < 0 || last_x < 0) {
			can_put_nemo = true;
			break;
		}

		if (board[last_y][last_x] == false) {
			can_put_nemo = true;
			break;
		}
	}

	if (can_put_nemo) {
		board[y][x] = true;
		backtracking(id + 1);
		board[y][x] = false;
	}

	backtracking(id + 1);
}

int main(void) {
	cin >> N >> M;

	board = vector<vector<bool>>(N, vector<bool>(M, false));

	backtracking(0);
	cout << result;

	return 0;
}