#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[y][x] != '.') {
				board[y][M - 1 - x] = board[y][x];
			}
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cout << board[y][x];
		}

		cout << "\n";
	}

	return 0;
}