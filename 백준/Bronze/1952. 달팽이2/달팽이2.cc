#include <cstdio>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

bool finish(const vector<vector<int>>& board) {
	for (int y = 0; y < board.size(); ++y) {
		for (int x = 0; x < board[0].size(); ++x) {
			if (board[y][x] == -1) {
				return false;
			}
		}
	}

	return true;
}

int main(void) {
	int M, N;
	scanf("%d%d", &M, &N);

	vector<vector<int>> board(M, vector<int>(N, -1));

	int d = 0;
	int y = 0, x = 0;
	int result = 0;
	board[0][0] = 0;

	while (true) {
		const int next_y = y + directions[d][0];
		const int next_x = x + directions[d][1];

		if (next_y < 0 || next_y >= M || next_x < 0 || next_x >= N) {
			d = (d + 1) % 4;
			++result;
			continue;
		}

		if (board[next_y][next_x] != -1) {
			d = (d + 1) % 4;
			++result;
			continue;
		}

		board[next_y][next_x] = d;
		y = next_y;
		x = next_x;
		if (finish(board)) {
			break;
		}
	}

	printf("%d\n", result);

	return 0;
}