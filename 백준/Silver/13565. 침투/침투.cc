#include <iostream>
#include <vector>

using namespace std;

constexpr int directions[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

int N, M;
bool result = false;

void flow(vector<vector<char>>& board, const int y, const int x) {
	board[y][x] = '1';
	if (y == N - 1) {
		result = true;
	}

	for (int i = 0; i < 4; ++i) {
		const int next_y = y + directions[i][0];
		const int next_x = x + directions[i][1];

		if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) {
			continue;
		}

		if (board[next_y][next_x] != '0') {
			continue;
		}

		flow(board, next_y, next_x);
	}
}

int main(void) {
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int x = 0; x < M; ++x) {
		if (board[0][x] == '0') {
			flow(board, 0, x);
		}
	}

	if (result) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}